cmake_minimum_required(VERSION 3.10.2)
project(Dhmem)
set(CMAKE_CXX_STANDARD 11)
include(ExternalProject)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


option(build_examples "Build the example executables" OFF)
option(build_perf "Build the performance executables" OFF)

add_subdirectory(dhmem)

if(build_examples)
    find_package(Henson REQUIRED)
    find_package(Decaf REQUIRED)

    add_subdirectory(examples)
endif()

if(build_perf)
    add_subdirectory(perf)
endif()
