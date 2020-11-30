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

//typedef dhmem::map<dhmem::string, std::any> mapany;

void die(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

void steer(Decaf *decaf, dhmem::Dhmem &dhmem)
{
    char *s;
    float eps;
    int i = 0;

    eps = (s = getenv("EPS")) ? atof(s) : 0.001;

    int &n = dhmem.simple<int>("myIntName");

    vector<pConstructData> in_data;
    while (++i < 100 && decaf->get(in_data, "s_in"))
    {
        fmt::print("n: {}\n", n);

        pConstructData &in_msg = in_data[0];

        float y, yp;

        std::fprintf(stderr, "s: getting x field\n");
        SimpleField<dhmem::handle> xfield1 = in_msg->getFieldData<SimpleField<dhmem::handle>>("x");
        std::fprintf(stderr, "s: done getting x field\n");

        std::fprintf(stderr, "s: getting x handle\n");
        dhmem::handle h = xfield1.getData();
        std::fprintf(stderr, "s: done getting x handle %lu\n", h);

        std::fprintf(stderr, "s: loading x\n");
        float &x = dhmem.load<float>(h);
        std::fprintf(stderr, "s: done loading x %f\n", x);

        y = in_msg->getFieldData<SimpleFieldf>("y").getData();
        yp = in_msg->getFieldData<SimpleFieldf>("yp").getData();

        if (abs(y / yp) < eps) break;
        x -= y / yp;

        std::fprintf(stderr, "s: saving x\n");
        dhmem::handle h2 = dhmem.save(x);
        std::fprintf(stderr, "s: done saving x %lu\n", h2);

        std::fprintf(stderr, "s: creating x field\n");
        SimpleField<dhmem::handle> xfield(h2);
        std::fprintf(stderr, "s: done creating x field\n");

        pConstructData out_msg;
        out_msg->appendData("x", xfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);

        decaf->put(out_msg, "s_out");
        decaf->commit();
    }

    decaf->terminate();
}

int main(int argc,
         char** argv)
{
    dhmem::Dhmem dhmem(dhmem::open_or_create, "foobar", 65536);

    Workflow workflow;
    Workflow::make_wflow_from_json(workflow, "decaf-henson.json");

    henson::ProcMap *procmap = henson::get_procmap();
    Decaf *decaf = new Decaf(procmap, MPI_COMM_WORLD, workflow);

    fmt::print("Hello from steer\n");
    steer(decaf, dhmem);
    fmt::print("Goodbye from steer\n");

    return 0;
}
