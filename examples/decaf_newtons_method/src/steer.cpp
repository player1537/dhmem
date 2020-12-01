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

    vector<pConstructData> in_data;
    while (++i < 100 && decaf->get(in_data, "s_in"))
    {
        pConstructData &in_msg = in_data[0];

        float &x = in_msg->getFieldData<SharedFieldf>("x").getData(dhmem);
        float y = in_msg->getFieldData<SimpleFieldf>("y").getData();
        float yp = in_msg->getFieldData<SimpleFieldf>("yp").getData();

        if (abs(y / yp) < eps) break;
        x -= y / yp;

        SharedFieldf xfield(x, dhmem);

        pConstructData out_msg;
        out_msg->appendData("x", xfield, DECAF_NOFLAG, DECAF_PRIVATE, DECAF_SPLIT_DEFAULT, DECAF_MERGE_DEFAULT);

        decaf->put(out_msg, "s_out");
        decaf->commit();
    }

    decaf->terminate();
}

int main(int argc, char** argv)
{
    if (!henson_active())
    {
        fmt::print("Must run under henson, but henson is not active\n");
        return 1;
    }

    if (henson_stop())
    {
        fmt::print("Stop, stop, stop at steer\n");
        return 1;
    }

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
