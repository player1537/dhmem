# vim: sta:et:sw=4:ts=4:sts=4:ai

cmake_minimum_required(VERSION 3.10.2)
project(PerformanceSyntheticDhmem)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(MPI REQUIRED)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/synthetic_dhmem.cpp
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/definitions.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/generate.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND bash -c "./venv/bin/python ./generate.py \$(cat definitions.txt) > ./src/synthetic_dhmem.cpp"
    VERBATIM
)

add_executable(perf_synthetic_dhmem src/synthetic_dhmem.cpp)
target_link_libraries(perf_synthetic_dhmem dhmem::dhmem Threads::Threads ${MPI_C_LIBRARIES})
target_include_directories(perf_synthetic_dhmem PUBLIC ${MPI_INCLUDE_PATH})

install(TARGETS perf_synthetic_dhmem EXPORT Perf DESTINATION bin)
