
#include "network.hpp"
#include <iostream>

static boost::asio::io_context io_context;
static boost::asio::ip::tcp::resolver resolver(io_context);

namespace net {

void connect(const std::string& host) {
    auto endpoints = resolver.resolve(host,"");
    std::cout << endpoints.size() << std::endl;
}

}

