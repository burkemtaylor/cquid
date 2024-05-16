cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 11)
set(target cquidNetworking)
set(version 0.0.0)

# Dependencies
find_package(Boost 1.85.0 REQUIRED)

# Sources
set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/${target}")
set(source_path  "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Build library
add_library(${target} SHARED
    src/TCPConnection.cpp   
    src/TCPServer.cpp
)

# Add include directories
target_include_directories(${target}
    PUBLIC 
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        ${Boost_INCLUDE_DIRS}
    PRIVATE
)
