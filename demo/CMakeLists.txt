cmake_minimum_required(VERSION 3.1)
project(Demo)

add_executable(evaluate src/evaluate.cpp)
target_link_libraries(evaluate dhmem::dhmem)

add_executable(steer src/steer.cpp)
target_link_libraries(steer dhmem::dhmem)

add_executable(visualize src/visualize.cpp)
target_link_libraries(visualize dhmem::dhmem)

install(TARGETS evaluate steer visualize EXPORT Demo DESTINATION bin)
