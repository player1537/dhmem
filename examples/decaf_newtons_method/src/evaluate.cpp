#include <decaf/decaf.hpp>
#include <bredala/data_model/simplefield.hpp>
#include <bredala/data_model/boost_macros.h>
#include <dhmem/dhmem.h>
#include <dhmem/support/decaf.h>

#include <assert.h>
#include <math.h>
#include <mpi.h>
#include <map>
#include <cstdlib>

#include <henson/data.h>
#include <henson/context.h>
#include <henson/context.hpp>

#include <fmt/format.h>
#include <fmt/ostream.h>

using namespace decaf;
using namespace std;

void die(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

void evaluate(Decaf *decaf, dhmem::Dhmem &dhmem)
{
    char *s;
    float x0, A, B, C;

    x0 = (s = getenv("X0")) ? atof(s) : 3.00;
    A = (s = getenv("A")) ? atof(s) : 1.0;
    B = (s = getenv("B")) ? atof(s) : 2.0;
    C = (s = getenv("C")) ? atof(s) : -3.0;

    int &n = dhmem.simple<int>("myIntName");

    vector<pConstructData> in_data;
    while (decaf->get(in_data, "e_in"))
    {
        ++n;

        pConstructData &in_msg = in_data[0];

        std::fprintf(stderr, "e: allocating x\n");
        float &x = dhmem.simple<float>("e_out__x");
        std::fprintf(stderr, "e: done allocating x\n");

        if (in_msg->isToken())
            x = x0;
        else
        {
            std::fprintf(stderr, "e: getting x field\n");
            SimpleField<dhmem::handle> xfield1 = in_msg->getFieldData<SimpleField<dhmem::handle>>("x");
            std::fprintf(stderr, "e: done getting x field\n");

            std::fprintf(stderr, "e: getting x handle\n");
            dhmem::handle h = xfield1.getData();
            std::fprintf(stderr, "e: done getting x handle %lu\n", h);

            std::fprintf(stderr, "e: loading x\n");
            x = dhmem.load<float>(h);
            std::fprintf(stderr, "e: done loading x %f\n", x);
        }

        float y, yp;
        y = A * x * x + B * x + C;
        yp = 2 * A * x + B;

        SimpleFieldf x0field(x0);
        SimpleFieldf Afield(A);
        SimpleFieldf Bfield(B);
        SimpleFieldf Cfield(C);

        std::fprintf(stderr, "e: saving x\n");
        dhmem::handle h = dhmem.save(x);
        std::fprintf(stderr, "e: done saving x %lu\n", h);

        std::fprintf(stderr, "e: creating x field\n");
        SimpleField<dhmem::handle> xfield(h);
        std::fprintf(stderr, "e: done creating x field\n");

        SimpleFieldf yfield(y);
        SimpleFieldf ypfield(yp);

        pConstructData out_msg;
        out_msg->appendData("x0", x0field, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("A", Afield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("B", Bfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("C", Cfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);

        std::fprintf(stderr, "e: appending x field\n");
        out_msg->appendData("x", xfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        std::fprintf(stderr, "e: done appending x field\n");

        out_msg->appendData("y", yfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("yp", ypfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);

        std::fprintf(stderr, "e: putting data\n");
        decaf->put(out_msg, "e_out");
        std::fprintf(stderr, "e: done putting data\n");

        std::fprintf(stderr, "e: committing data\n");
        decaf->commit();
        std::fprintf(stderr, "e: done committing data\n");
    }

    decaf->terminate();
}

int main(int argc,
         char** argv)
{
    if (!henson_active()) {}
    if (henson_stop()) {}

    dhmem::Dhmem dhmem(dhmem::open_or_create, "foobar", 65536);

    Workflow workflow;
    Workflow::make_wflow_from_json(workflow, "decaf-henson.json");

    henson::ProcMap *procmap = henson::get_procmap();
    Decaf *decaf = new Decaf(procmap, MPI_COMM_WORLD, workflow);

    fmt::print("Hello from evaluate\n");
    evaluate(decaf, dhmem);
    fmt::print("Goodbye from evaluate\n");

    return 0;
}

