cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 11)
set(target cquidClient)

add_executable(${target} main.cpp)

target_link_libraries(${target} cquidNetworking)


