# Dhmem: Simplified Cross-Workflow Communication



## Building/Installing

To build, either vendor the source code and include with CMake's `add_subdirectory` or add via `ExternalProject_Add`.

## Example

```c++
#include <dhmem/dhmem.h>
#include <cstdio>

int main(int argc, char **argv) {
    dhmem::Dhmem dhmem("shared_memory_namespace");

    auto &n = dhmem.shared<int>();
    auto &mutex = dhmem.shared<dhmem::mutex>();
    
    {
        dhmem::scoped_lock lock(mutex);
        ++n;
        std::printf("n = %d\n", n);
    }

    std::printf("Press Enter to quit...\n");
    std::getchar();

    return 0;
}
```
