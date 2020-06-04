cmake_minimum_required(VERSION 3.10.2)

option(build_demo "Build the demo executables" ON)

add_subdirectory(dhmem)

if(build_demo)
    add_subdirectory(demo)
endif()
