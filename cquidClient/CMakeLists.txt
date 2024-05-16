cmake_minimum_required(VERSION 3.0.0)
project(cquidClient VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(cquidClient main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        cquidNetworking
)

target_link_directories(${PROJECT_NAME}
    PUBLIC
        cquidNetworking
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
