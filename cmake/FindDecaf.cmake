cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)


# expects EP_HENSON to exist


set(EP_DECAF "Decaf")
ExternalProject_Add(
    ${EP_DECAF}

    PREFIX ${EP_DECAF}
    GIT_REPOSITORY https://bitbucket.org/tpeterka1/decaf.git
    GIT_TAG 032fceed8a66c99d2de83c7b1e5410993d66f9d9  # origin/decaf-henson

    BUILD_ALWAYS OFF
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/ext/${EP_DECAF}

    UPDATE_DISCONNECTED TRUE
    UPDATE_COMMAND ""
    PATCH_COMMAND cd <SOURCE_DIR> && patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch-decaf.patch

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
set(Decaf_EXECUTABLES
    ${INSTALL_DIR}/examples/henson/python/decaf-henson_python
)
ExternalProject_Get_Property(${EP_DECAF} SOURCE_DIR)
set(Decaf_FMT_INCLUDE_DIR ${SOURCE_DIR}/include)

install(
    PROGRAMS
        ${Decaf_EXECUTABLES}
    DESTINATION
        bin
)
