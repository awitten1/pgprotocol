#include <array>
#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "network.hpp"

struct Args {
    std::string password;
    uint16_t port;
    std::string host;
    std::string dbname;
};

Args parse_cli_params(int argc, char** argv) {
    Args args;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        auto pos = arg.find("=");
        if (pos == std::string::npos) {
            std::cerr << "arguments must be key-value pairs formatted as <key>=<value>" 
                << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string key(arg.begin(), arg.begin() + pos);
        std::string value(arg.begin() + pos + 1, arg.end());
        if (key == "password") {
            args.password = value;
        } else if (key == "host") {
            args.host = value;
        } else if (key == "port") {
            args.port = std::stoi(value);
        } else if (key == "dbname") {
            args.dbname = value;
        } else {
            std::cerr << "unknown key " << key << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return args;
}

int main(int argc, char** argv) {
    Args args = parse_cli_params(argc, argv);
    std::cout << args.dbname << " " << args.host << " " << args.port << std::endl;
    net::connect(args.host, args.port);
    return 0;
}