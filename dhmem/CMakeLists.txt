cmake_minimum_required(VERSION 3.10.2)
project(Dhmem)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.65.1) 

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
install(DIRECTORY include/dhmem
    DESTINATION include)
