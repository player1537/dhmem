cmake_minimum_required(VERSION 3.10.2)
project(PerformanceSyntheticDhmem)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(perf_synthetic_dhmem src/synthetic_dhmem.cpp)
target_link_libraries(perf_synthetic_dhmem dhmem::dhmem Threads::Threads)

install(TARGETS perf_synthetic_dhmem EXPORT Perf DESTINATION bin)
