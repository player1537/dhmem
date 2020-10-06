#include <decaf/decaf.hpp>
#include <bredala/data_model/simplefield.hpp>
#include <bredala/data_model/boost_macros.h>

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

void visualize(Decaf *decaf)
{
    vector<pConstructData> in_data;
    while (decaf->get(in_data, "v_in"))
    {
        pConstructData &in_msg = in_data[0];

        float x0, A, B, C, x, y, yp;
        x0 = in_msg->getFieldData<SimpleFieldf>("x0").getData();
        A = in_msg->getFieldData<SimpleFieldf>("A").getData();
        B = in_msg->getFieldData<SimpleFieldf>("B").getData();
        C = in_msg->getFieldData<SimpleFieldf>("C").getData();
        x = in_msg->getFieldData<SimpleFieldf>("x").getData();
        y = in_msg->getFieldData<SimpleFieldf>("y").getData();
        yp = in_msg->getFieldData<SimpleFieldf>("yp").getData();

        fprintf(stderr, "vis: x0=%f A=%f B=%f C=%f x=%f y=%f yp=%f\n", x0, A, B, C, x, y, yp);
    }

    decaf->terminate();
}

int main(int argc,
         char** argv)
{
    Workflow workflow;
    Workflow::make_wflow_from_json(workflow, "decaf-henson.json");

    henson::ProcMap *procmap = henson::get_procmap();
    Decaf *decaf = new Decaf(procmap, MPI_COMM_WORLD, workflow);

    fmt::print("Hello from visualize\n");
    visualize(decaf);
    fmt::print("Goodbye from visualize\n");

    return 0;
}
