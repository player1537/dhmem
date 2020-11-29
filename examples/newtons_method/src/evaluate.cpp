#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>
#include <array>
#include "common.h"

void evaluate(dhmem::Dhmem &dhmem) {
    auto &s_out_e_in_mutex = dhmem.simple<dhmem::mutex>("s_out_e_in_mutex");
    auto &s_out_e_in_cond = dhmem.simple<dhmem::cond>("s_out_e_in_cond");

    auto &e_out_s_in_mutex = dhmem.simple<dhmem::mutex>("e_out_s_in_mutex");
    auto &e_out_s_in_cond = dhmem.simple<dhmem::cond>("e_out_s_in_cond");

    auto &e_out_v_in_mutex = dhmem.simple<dhmem::mutex>("e_out_v_in_mutex");
    auto &e_out_v_in_cond = dhmem.simple<dhmem::cond>("e_out_v_in_cond");

    auto &e_out = dhmem.vector<e_out_data>("e_out");
    auto &e_in = dhmem.vector<e_in_data>("s_out");

    dhmem::scoped_lock lock(s_out_e_in_mutex);
    for (int i=0; ; ++i) {
        if (i == 0) {
            std::printf("initial\n");
            e_in.resize(1);
            char *s;
            e_in[0].a = (s = std::getenv("A")) ? std::atof(s) :  1.00;
            e_in[0].b = (s = std::getenv("B")) ? std::atof(s) :  2.00;
            e_in[0].c = (s = std::getenv("C")) ? std::atof(s) : -3.00;
            e_in[0].x = (s = std::getenv("X")) ? std::atof(s) :  3.00;
        } else {
            std::printf("waiting\n");
            s_out_e_in_cond.wait(lock);
        }

        {
            std::printf("e_in.size() = %d\n", (int)e_in.size());

            e_out.resize(e_in.size());
            for (int j=0; j<e_in.size(); ++j) {
                float a = e_in[j].a;
                float b = e_in[j].b;
                float c = e_in[j].c;
                float x = e_in[j].x;

                float y = a * x * x + b * x + c;
                float yp = 2 * a * x + b;

                e_out[j] = { a, b, c, x, y, yp };
            }
        }

        {
            std::printf("notifying cond\n");
            dhmem::scoped_lock lock(e_out_s_in_mutex);
            e_out_s_in_cond.notify_one();
        }

        {
            dhmem::scoped_lock lock(e_out_v_in_mutex);
            e_out_v_in_cond.notify_one();
        }

        if (e_out.size() == 0) {
            std::printf("breaking\n");
            break;
        }
    }
}

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");

    dhmem::Dhmem dhmem(dhmem::open_or_create, "foobar", 65536);

    evaluate(dhmem);
}
