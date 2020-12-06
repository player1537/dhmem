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

void steer(dhmem::Dhmem &dhmem) {
    float a, b, c, x, y, yp;
    for (int i=0; i<10; ++i) {
        std::fprintf(stderr, "s: i=%d\n", i);

        henson_load_float("a", &a);
        henson_load_float("b", &b);
        henson_load_float("c", &c);
        auto &xs = henson_load_handle<dhmem::vector<float>>("xs", dhmem);
        auto &ys = henson_load_handle<dhmem::vector<float>>("ys", dhmem);
        auto &yps = henson_load_handle<dhmem::vector<float>>("yps", dhmem);

        for (int j=0; j<xs.size(); ++j) {
            float x = xs[j];
            float y = ys[j];
            float yp = yps[j];

            x -= y / yp;

            xs[j] = x;
        }

        henson_save_float("a", a);
        henson_save_float("b", b);
        henson_save_float("c", c);
        henson_save_handle("xs", xs, dhmem);

        std::fprintf(stderr, "s: yield\n");
        henson_yield();
    }
}

int main(int argc, char** argv)
{
    std::fprintf(stderr, "s: hello\n");

    if (!henson_active())
    {
        printf("Must run under henson, but henson is not active\n");
        return 1;
    }

    if (henson_stop())
        return 0;

    dhmem::Dhmem dhmem(dhmem::open_only, "foobar");

    steer(dhmem);

    if (!henson_active())
        MPI_Finalize();

    return 0;
}
