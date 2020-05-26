#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");
    dhmem::DhmemAllocator<int> a("foobar");

    {
        auto a1 = std::shared_ptr<int>(a.allocate(1), [&a](int *x) { a.deallocate(x, 1); });
        *a1 = 123;

        std::printf("a1 = %d\n", *a1);
    }

    a.close();
}
