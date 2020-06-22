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

    auto &s_out = dhmem.vector<s_out_data>("s_out");
    auto &s_in = dhmem.vector<s_in_data>("e_out");

    dhmem::scoped_lock lock(e_out_s_in_mutex);
    for (;;) {
        std::printf("waiting\n");
        e_out_s_in_cond.wait(lock);

        {
            std::printf("calculating\n");

            s_out.clear();
            for (int j=0; j<s_in.size(); ++j) {
                float a = s_in[j].a;
                float b = s_in[j].b;
                float c = s_in[j].c;
                float x = s_in[j].x;
                float y = s_in[j].y;
                float yp = s_in[j].yp;

                if (std::abs(y / yp) < 0.001) {
                    std::printf("this one is done\n");
                    continue;
                }

                x -= y / yp;

                s_out.push_back({ a, b, c, x });
            }
        }

        {
            std::printf("sending\n");
            dhmem::scoped_lock lock(s_out_e_in_mutex);
            s_out_e_in_cond.notify_one();
            if (s_out.size() == 0) {
                std::printf("breaking\n");
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");

    dhmem::Dhmem dhmem("foobar");

    evaluate(dhmem);
}
