#pragma once

#include <cstdint>
#include <cstring>
#include <endian.h>
#include <memory>
#include <string>
#include <boost/asio.hpp>

struct StartupMessage {
    int32_t protocol_version = 196610;
    std::string database;
    std::string user;

    constexpr static inline const char* database_str = "database";
    constexpr static inline const char* user_str = "user";
    constexpr static inline int dblen = std::char_traits<char>::length(database_str);
    constexpr static inline int userlen = std::char_traits<char>::length(user_str);

    std::unique_ptr<char[]> serialize() {
        int32_t message_length = sizeof(message_length) + sizeof(protocol_version) + database.size() + 1 + dblen + 1 \
            + user.size() + 1 + userlen + 1;

        std::unique_ptr<char[]> buf(new char[message_length]);
        int32_t message_length_be = htonl(message_length);
        int32_t protocol_version_be = htonl(protocol_version);

        int offset = 0;
        memcpy(buf.get() + offset, &message_length_be, 4);
        offset += 4;
        memcpy(buf.get() + offset, &protocol_version_be, 4);
        offset += 4;
        memcpy(buf.get() + offset, database_str, dblen + 1);
        offset += dblen + 1;
        memcpy(buf.get() + offset, database.c_str(), database.size() + 1);
        offset += database.size() + 1;
        memcpy(buf.get() + offset, user_str, userlen);
        offset += userlen + 1;
        memcpy(buf.get() + offset, user.c_str() + 1, user.size() + 1);

        return buf;
    }
};