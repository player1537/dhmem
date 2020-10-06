cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)

option(build_examples "Build the example executables" ON)

add_subdirectory(dhmem)

if(build_examples)
    add_subdirectory(examples)
endif()
