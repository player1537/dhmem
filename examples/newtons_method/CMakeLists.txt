cmake_minimum_required(VERSION 3.10.2)
project(NewtonsMethod)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(evaluate src/evaluate.cpp)
target_link_libraries(evaluate dhmem::dhmem Threads::Threads)

add_executable(steer src/steer.cpp)
target_link_libraries(steer dhmem::dhmem Threads::Threads)

add_executable(visualize src/visualize.cpp)
target_link_libraries(visualize dhmem::dhmem Threads::Threads)

install(TARGETS evaluate steer visualize EXPORT Demo DESTINATION bin)
