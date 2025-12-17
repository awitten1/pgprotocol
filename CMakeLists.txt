cmake_minimum_required(VERSION 3.22)

project(pgprotocol LANGUAGES CXX)

find_package(Boost REQUIRED)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE network)
