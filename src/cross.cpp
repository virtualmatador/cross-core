//
//  interface.cpp
//  cross
//
//  Created by Ali Asadpoor on 1/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#include <sstream>

#include "cross.h"
#include "main.h"
#include "stage.h"

void cross::Begin()
{
    life_cycle::Begin();
}

void cross::End()
{
    life_cycle::End();
}

void cross::Create()
{
    life_cycle::Create();
}

void cross::Destroy()
{
    life_cycle::Destroy();
}

void cross::Start()
{
    life_cycle::Start();
    cross::Restart();
}

void cross::Stop()
{
    ++core::Stage::index_;
    core::Stage::stage_.reset(nullptr);
    life_cycle::Stop();
}

void cross::Restart()
{
    ++core::Stage::index_;
    life_cycle::Restart();
}

void cross::Escape()
{
    core::Stage::stage_->Escape();
}

void cross::Handle(const char* id, const char* command, const char* info)
{
    core::Stage::stage_->Handle(id, command, info);
}

void cross::HandleAsync(const std::int32_t receiver, const char* id, const char* command, const char* info)
{
    if (core::Stage::index_ == receiver)
    {
        core::Stage::stage_->Handle(id, command, info);
    }
}

void cross::FeedUri(const char* uri, std::function<void(const std::vector<unsigned char>&)>&& consume)
{
    int32_t receiver = 0;
    uri += sizeof("cross://") - 1;
    std::istringstream is{ uri };
    is >> receiver;
    uri += (std::size_t)is.tellg() + 1;
    if (core::Stage::stage_->index_ == receiver)
    {
        core::Stage::stage_->FeedUri(uri, std::move(consume));
    }
}
