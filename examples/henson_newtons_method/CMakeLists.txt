cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)
project(HensonNewtonsMethod)


find_package(Boost REQUIRED system serialization)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


find_package(MPI)


set(_libraries
    dhmem::dhmem
    Threads::Threads
    ${Henson_LIBRARIES}
    ${MPI_C_LIBRARIES}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
)

set(_include_dirs
    ${Henson_INCLUDE_DIR}
    ${Decaf_FMT_INCLUDE_DIR}
    ${MPI_INCLUDE_PATH}
)

add_library(henson_evaluate SHARED src/evaluate.cpp)
target_link_libraries(henson_evaluate ${_libraries})
target_include_directories(henson_evaluate PRIVATE ${_include_dirs})

add_library(henson_steer SHARED src/steer.cpp)
target_link_libraries(henson_steer ${_libraries})
target_include_directories(henson_steer PRIVATE ${_include_dirs})

add_library(henson_visualize SHARED src/visualize.cpp)
target_link_libraries(henson_visualize ${_libraries})
target_include_directories(henson_visualize PRIVATE ${_include_dirs})

install(
    TARGETS
        henson_evaluate
        henson_steer
        henson_visualize
    EXPORT 
        henson_newtons_method
    DESTINATION
        bin
)
