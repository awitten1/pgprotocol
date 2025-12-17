cmake_minimum_required(VERSION 3.22)

project(pgprotocol LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED CONFIG)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE network)
