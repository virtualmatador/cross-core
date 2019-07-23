//
//  stage.cpp
//  cross
//
//  Created by Ali Asadpoor on 4/10/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#include "stage.h"

#include <string>
#include <sstream>
#include <thread>


int core::Stage::index_;
std::unique_ptr<core::Stage> core::Stage::stage_;
std::string core::Stage::public_key_;
asio::io_service core::Stage::io_service_;
asio::ssl::context core::Stage::ssl_(asio::ssl::context::sslv3_client);

core::Stage::Stage()
{
}

core::Stage::~Stage()
{
}

void core::Stage::Handle(const char* message)
{
    std::istringstream parser(message);
    std::string id, command, info;
    parser >> id >> command;
    std::getline(parser, info);
    handlers_[id](command.c_str(), info.c_str());
}

std::thread core::Stage::Backend(const char* path, Pack request)
{
    std::thread network([index = index_](){
        asio::ssl::stream<asio::ip::tcp::socket> sock(io_service_, ssl_);
        bridge::PostThreadMessage(index, "key=value&");
    });
    return network;
}
