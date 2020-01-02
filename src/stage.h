//
//  stage.h
//  cross
//
//  Created by Ali Asadpoor on 4/8/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_STAGE_H
#define CORE_STAGE_H

#include "bridge.h"
#include "define.h"

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
        void Handle(const char* id, const char* command, const char* info);
        virtual void Escape() = 0;

    public:
        static int index_;
        static std::unique_ptr<Stage> stage_;
    };
}

#endif //CORE_STAGE_H
