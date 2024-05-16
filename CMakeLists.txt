cmake_minimum_required(VERSION 3.29)
project(cquid VERSION 0.0.1)

# include(CTest)
# enable_testing()

add_subdirectory(cquidNetworking)
add_subdirectory(cquidClient)
add_subdirectory(cquidServer)

# add_executable(cquid main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
