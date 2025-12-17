
add_library(network network.cpp)
target_link_libraries(network PUBLIC Boost::boost)
target_include_directories(network PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")