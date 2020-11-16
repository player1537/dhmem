cmake_minimum_required(VERSION 3.10.2)
project(PerformanceThroughputDhmem)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(perf_throughput_dhmem src/throughput_dhmem.cpp)
target_link_libraries(perf_throughput_dhmem dhmem::dhmem Threads::Threads)

install(TARGETS perf_throughput_dhmem EXPORT Perf DESTINATION bin)
