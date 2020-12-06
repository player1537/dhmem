#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <mpi.h>

#include <henson/data.h>
#include <henson/data.hpp>
#include <henson/context.h>
#include <dhmem/dhmem.h>
#include <dhmem/support/henson.h>

void evaluate(dhmem::Dhmem &dhmem) {
    float a, b, c;
    auto &xs = dhmem.container<dhmem::vector<float>>("xs");
    auto &ys = dhmem.container<dhmem::vector<float>>("ys");
    auto &yps = dhmem.container<dhmem::vector<float>>("yps");

    for (int i=0; i<10; ++i) {
        std::fprintf(stderr, "e: i=%d\n", i);

        if (i == 0) {
            a =  1.00;
            b =  2.00;
            c = -3.00;
            for (float x=-9.00; x<9.00; x+=2.00) {
                xs.push_back(x);
            }
        } else {
            henson_load_float("a", &a);
            henson_load_float("b", &b);
            henson_load_float("c", &c);
            xs = henson_load_handle<dhmem::vector<float>>("xs", dhmem);
        }

        ys.clear();
        yps.clear();
        for (float x : xs) {
            float y = a * x * x + b * x + c;
            float yp = 2 * a * x + b;

            ys.push_back(y);
            yps.push_back(yp);
        }

        henson_save_float("a", a);
        henson_save_float("b", b);
        henson_save_float("c", c);
        henson_save_handle("xs", xs, dhmem);
        henson_save_handle("ys", ys, dhmem);
        henson_save_handle("yps", yps, dhmem);

        std::fprintf(stderr, "e: yield\n");
        henson_yield();
    }
}

int main(int argc, char** argv)
{
    std::fprintf(stderr, "e: hello\n");

    if (!henson_active())
    {
        printf("Must run under henson, but henson is not active\n");
        return 1;
    }

    if (henson_stop())
        return 0;

    dhmem::Dhmem dhmem(dhmem::force_create_only, "foobar", 65536);

    evaluate(dhmem);

    if (!henson_active())
        MPI_Finalize();

    return 0;
}
