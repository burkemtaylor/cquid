cmake_minimum_required(VERSION 3.0.0)
project(cquidNetworking VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(cquidNetworking src/base.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
