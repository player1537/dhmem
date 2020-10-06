#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>
#include <array>
#include "common.h"

void visualize(dhmem::Dhmem &dhmem) {
    auto &e_out_v_in_mutex = dhmem.simple<dhmem::mutex>("e_out_v_in_mutex");
    auto &e_out_v_in_cond = dhmem.simple<dhmem::cond>("e_out_v_in_cond");

    auto &v_in = dhmem.vector<v_in_data>("e_out");

    dhmem::scoped_lock lock(e_out_v_in_mutex);
    for (;;) {
        std::printf("waiting\n");
        e_out_v_in_cond.wait(lock);

        {
            std::printf("calculating\n");

            for (int j=0; j<v_in.size(); ++j) {
                float a = v_in[j].a;
                float b = v_in[j].b;
                float c = v_in[j].c;
                float x = v_in[j].x;
                float y = v_in[j].y;
                float yp = v_in[j].yp;

                std::printf("vis: a=%f b=%f c=%f x=%f y=%f yp=%f\n", a, b, c, x, y, yp);
            }
        }

        if (v_in.size() == 0) {
            std::printf("done\n");
            break;
        }
    }
}

int main(int argc, char **argv) {
    std::printf("Hello from visualize\n");

    dhmem::Dhmem dhmem("foobar");

    visualize(dhmem);
}
