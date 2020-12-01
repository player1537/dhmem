cmake_minimum_required(VERSION 3.10.2)
project(Dhmem)
include(ExternalProject)

option(build_examples "Build the example executables" OFF)
option(build_perf "Build the performance executables" OFF)

add_subdirectory(dhmem)

if(build_examples)
    add_subdirectory(examples)
endif()

if(build_perf)
    add_subdirectory(perf)
endif()
