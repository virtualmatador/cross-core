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
    std::getline(parser, info, '\0');
    handlers_[id](command.c_str(), info.c_str());
}
