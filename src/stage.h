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
#include <functional>
#include <memory>
#include <thread>
#include <vector>

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
        virtual void FeedUri(const char* uri, std::function<void(
            const std::vector<unsigned char>&)>&& consume) = 0;

    public:
        static int index_;
        static std::unique_ptr<Stage> stage_;
    };
}

#endif //CORE_STAGE_H
