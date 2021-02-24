cmake_minimum_required(VERSION 3.10.2)
include(ExternalProject)


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
    PATCH_COMMAND cd <SOURCE_DIR> && patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch-henson.patch

    CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
	-DPYBIND11_PYTHON_VERSION:STRING=${PYBIND11_PYTHON_VERSION}
)
ExternalProject_Get_Property(${EP_HENSON} INSTALL_DIR)
set(Henson_INSTALL_DIR ${INSTALL_DIR})
set(Henson_INCLUDE_DIR ${INSTALL_DIR}/include)
set(Henson_LINK_DIR ${INSTALL_DIR}/lib)
set(Henson_LIBRARIES ${Henson_LINK_DIR}/libhenson.a)
set(Henson_EXECUTABLES
    ${INSTALL_DIR}/bin/henson-chai
    ${INSTALL_DIR}/bin/henson-exec
    ${INSTALL_DIR}/bin/henson-hwl
)

install(
    PROGRAMS
        ${Henson_EXECUTABLES}
    DESTINATION
        bin
)
