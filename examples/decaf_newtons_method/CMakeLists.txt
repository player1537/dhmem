cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)
project(DecafNewtonsMethod)



# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# the RPATH to be used when installing, but only if it's not a system directory
# list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
# if("${isSystemDir}" STREQUAL "-1")
    # set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" "${CMAKE_BUILD_PREFIX}/lib")
# endif("${isSystemDir}" STREQUAL "-1")



set(EP_HENSON Henson)
ExternalProject_Add(
    ${EP_HENSON}

    PREFIX ${EP_HENSON}

    GIT_REPOSITORY https://github.com/henson-insitu/henson.git
    GIT_TAG e6584dd2275b1ab208a5dd759148513f741e8bef

    BUILD_ALWAYS OFF
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/ext/${EP_HENSON}

    UPDATE_DISCONNECTED TRUE
    UPDATE_COMMAND ""

    CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)
ExternalProject_Get_Property(${EP_HENSON} INSTALL_DIR)
set(Henson_INSTALL_DIR ${INSTALL_DIR})
set(Henson_INCLUDE_DIR ${INSTALL_DIR}/include)
set(Henson_LINK_DIR ${INSTALL_DIR}/lib)
set(Henson_LIBRARIES ${Henson_LINK_DIR}/libhenson.a)

set(EP_DECAF "Decaf")
ExternalProject_Add(
    ${EP_DECAF}

    PREFIX ${EP_DECAF}
    GIT_REPOSITORY https://bitbucket.org/tpeterka1/decaf.git
    GIT_TAG 032fceed8a66c99d2de83c7b1e5410993d66f9d9  # origin/decaf-henson

    BUILD_ALWAYS OFF
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/ext/${EP_DECAF}

    #UPDATE_DISCONNECTED TRUE
    #UPDATE_COMMAND ""
    PATCH_COMMAND cd <SOURCE_DIR> && patch -p1 < ${CMAKE_CURRENT_SOURCE_DIR}/patch-decaf.patch

    CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DHENSON_INCLUDE_DIR:PATH=${Henson_INSTALL_DIR}
        -DHENSON_LIBRARY:PATH=${Henson_INSTALL_DIR}/lib/libhenson.a
        -Dbuild_examples:BOOL=ON
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
)
ExternalProject_Add_stepDependencies(${EP_DECAF}
    build
        ${EP_HENSON}
)
ExternalProject_Get_Property(${EP_DECAF} INSTALL_DIR)
set(Decaf_INSTALL_DIR ${INSTALL_DIR})
set(Decaf_INCLUDE_DIR ${INSTALL_DIR}/include)
set(Decaf_LINK_DIR ${INSTALL_DIR}/lib)
set(Decaf_LIBRARIES
    ${Decaf_LINK_DIR}/libdecaf.a
    ${Decaf_LINK_DIR}/libbredala_transport_mpi.so
    ${Decaf_LINK_DIR}/libbredala_datamodel.so
    ${Decaf_LINK_DIR}/libdca.so
    ${Decaf_LINK_DIR}/libmanala.so
)
ExternalProject_Get_Property(${EP_DECAF} SOURCE_DIR)
set(Decaf_FMT_INCLUDE_DIR ${SOURCE_DIR}/include)

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
