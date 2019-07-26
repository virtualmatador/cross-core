//
//  stage.h
//  cross
//
//  Created by Ali Asadpoor on 4/8/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_STAGE_H
#define CORE_STAGE_H

#include "pack.h"
#include "bridge.h"
#include "define.h"

#include <asio.hpp>
#include <asio/ssl.hpp>

#include <map>
#include <string>
#include <functional>
#include <memory>
#include <thread>

namespace core
{
    class Stage
    {
    protected:
        using HANDLER = std::function<void(const char* command, const char* info)>;
        std::map<std::string, HANDLER> handlers_;

    public:
        Stage();
        virtual ~Stage();
        void Handle(const char* message);
        virtual void Escape() = 0;

    protected:
        std::thread Backend(const char* path, Pack request);

    public:
        static int index_;
        static std::unique_ptr<Stage> stage_;
        static std::string public_key_;
        static asio::io_service io_service_;
        static asio::ssl::context ssl_;
    };
}

#endif //CORE_STAGE_H
