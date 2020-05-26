cmake_minimum_required(VERSION 3.1)
project(Dhmem)

find_library(REALTIME_EXTENSIONS rt)

add_library(dhmem SHARED src/dhmem.cpp include/dhmem/dhmem.h)
target_include_directories(dhmem PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
if(REALTIME_EXTENSIONS)
    target_link_libraries(dhmem PUBLIC ${REALTIME_EXTENSIONS})
endif()


add_library(dhmem::dhmem ALIAS dhmem)
install(TARGETS dhmem
    EXPORT dhmem-export
    DESTINATION lib)
install(EXPORT dhmem-export
    NAMESPACE dhmem::
    FILE dhmem-config.cmake
    DESTINATION lib/cmake/dhmem)
