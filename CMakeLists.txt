cmake_minimum_required(VERSION 3.1)

option(build_demo "Build the demo executables" ON)

add_subdirectory(dhmem)

if(build_demo)
    add_subdirectory(demo)
endif()
