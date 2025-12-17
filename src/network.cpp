
#include "network.hpp"
#include <iostream>
#include <string>

static boost::asio::io_context io_context;
static boost::asio::ip::tcp::resolver resolver(io_context);

namespace net {

void connect(const std::string& host, uint16_t portnum) {
    auto endpoints = resolver.resolve(host,std::to_string(portnum));
    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    if (socket.is_open()) {
        socket.write_some();
    }
    
    std::cout << endpoints.size() << std::endl;
    std::cout << endpoints.begin()->endpoint().address() << std::endl;
}

}

