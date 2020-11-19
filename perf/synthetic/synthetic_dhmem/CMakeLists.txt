cmake_minimum_required(VERSION 3.10.2)
project(PerformanceSyntheticDhmem)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(MPI REQUIRED)

add_executable(perf_synthetic_dhmem src/synthetic_dhmem.cpp)
target_link_libraries(perf_synthetic_dhmem dhmem::dhmem Threads::Threads ${MPI_C_LIBRARIES})
target_include_directories(perf_synthetic_dhmem PUBLIC ${MPI_INCLUDE_PATH})

install(TARGETS perf_synthetic_dhmem EXPORT Perf DESTINATION bin)
