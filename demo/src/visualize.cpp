#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>
#include <array>

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");

    dhmem::Dhmem dhmem("foobar");

    auto &vec = dhmem.vector<int>("myvec");
    vec.resize(1024);
    for (int i=0; i<1024; ++i) {
        vec[i] = 10000 + i;
    }

    auto &count = dhmem.simple<int>("mycount");
    count = 2;

    std::printf("vec[100] = %d; count = %d\n", vec[100], count);

    std::getchar();

    std::printf("vec[100] = %d; count = %d\n", vec[100], count);
}
