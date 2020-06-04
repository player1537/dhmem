#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>
#include <array>

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");
    dhmem::DhmemAllocator<void> v("foobar");

    auto a1 = v.as<std::array<int, 1024>>().make_shared();
    auto a1v = *a1.get();

    for (int i=0; i<1024; ++i) {
        a1v[i] = i;
    }

    std::printf("a1v[100] = %d\n", a1v[100]);
}
