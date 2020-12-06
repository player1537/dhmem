cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)
project(DecafNewtonsMethod)


find_package(Boost REQUIRED system serialization)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(MPI)

# set(CMAKE_SKIP_BUILD_RPATH FALSE)
# set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
# set(CMAKE_INSTALL_RPATH "")
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

set(_libraries
    dhmem::dhmem
    Threads::Threads
    ${Decaf_LIBRARIES}
    ${Henson_LIBRARIES}
    ${MPI_C_LIBRARIES}
    ${CMAKE_DL_LIBS}
    ${Boost_LIBRARIES}
)

set(_include_dirs
    ${Decaf_INCLUDE_DIR}
    ${Henson_INCLUDE_DIR}
    ${Decaf_FMT_INCLUDE_DIR}
    ${MPI_INCLUDE_PATH}
)

set(_compile_defs
    TRANSPORT_MPI=1
)


add_library(decaf_evaluate SHARED src/evaluate.cpp)
target_link_libraries(decaf_evaluate ${_libraries})
target_include_directories(decaf_evaluate PRIVATE ${_include_dirs})
target_compile_definitions(decaf_evaluate PRIVATE ${_compile_defs})

add_library(decaf_steer SHARED src/steer.cpp)
target_link_libraries(decaf_steer ${_libraries})
target_include_directories(decaf_steer PRIVATE ${_include_dirs})
target_compile_definitions(decaf_steer PRIVATE ${_compile_defs})

add_library(decaf_visualize SHARED src/visualize.cpp)
target_link_libraries(decaf_visualize ${_libraries})
target_include_directories(decaf_visualize PRIVATE ${_include_dirs})
target_compile_definitions(decaf_visualize PRIVATE ${_compile_defs})

set_target_properties(
    decaf_evaluate
    decaf_steer
    decaf_visualize
    PROPERTIES
        SKIP_BUILD_RPATH FALSE
        BUILD_WITH_INSTALL_RPATH FALSE
        INSTALL_RPATH_USE_LINK_PATH FALSE
        INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${CMAKE_BUILD_PREFIX}/lib;${Decaf_LINK_DIR};${Henson_LINK_DIR}"
)
get_target_property(_foo decaf_evaluate INSTALL_RPATH)
message("_foo = ${_foo}")

install(
    TARGETS
        decaf_evaluate
        decaf_steer
        decaf_visualize
    EXPORT 
        decaf_newtons_method
    DESTINATION
        bin
)
