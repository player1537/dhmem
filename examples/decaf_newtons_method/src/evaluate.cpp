#include <decaf/decaf.hpp>
#include <bredala/data_model/simplefield.hpp>
#include <bredala/data_model/boost_macros.h>
#include <dhmem/dhmem.h>
//#include <dhmem/support/decaf.h>

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

        float &x = dhmem.simple<float>("e_out__x");
        if (in_msg->isToken())
            x = x0;
        else
        {
            SimpleFieldf field = in_msg->getFieldData<SimpleFieldf>("x");
            if (!field) die("'x' not in message field");
            x = field.getData();
        }

        float y, yp;
        y = A * x * x + B * x + C;
        yp = 2 * A * x + B;

        SimpleFieldf x0field(x0);
        SimpleFieldf Afield(A);
        SimpleFieldf Bfield(B);
        SimpleFieldf Cfield(C);
        SimpleField<dhmem::handle> xfield(dhmem.save(x));
        SimpleFieldf yfield(y);
        SimpleFieldf ypfield(yp);

        pConstructData out_msg;
        out_msg->appendData("x0", x0field, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("A", Afield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("B", Bfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("C", Cfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("x", xfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("y", yfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);
        out_msg->appendData("yp", ypfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);

        decaf->put(out_msg, "e_out");
        decaf->commit();
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

