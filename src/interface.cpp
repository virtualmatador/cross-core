//
//  interface.cpp
//  cross
//
//  Created by Ali Asadpoor on 1/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#include "interface.h"
#include "main.h"
#include "stage.h"
#include "runner.h"

void interface::Begin()
{
    life_cycle::Begin();
}

void interface::End()
{
    life_cycle::End();
}

void interface::Create()
{
    life_cycle::Create();
}

void interface::Destroy()
{
    life_cycle::Destroy();
}

void interface::Start()
{
    life_cycle::Start();
    interface::Restart();
}

void interface::Stop()
{
    ++core::Stage::index_;
    core::Stage::stage_.reset(nullptr);
    life_cycle::Stop();
}

void interface::Restart()
{
    ++core::Stage::index_;
    life_cycle::Restart();
}

void interface::Escape()
{
    core::Stage::stage_->Escape();
}

void interface::Handle(const char* id, const char* command, const char* info)
{
    core::Stage::stage_->Handle(id, command, info);
}

void interface::HandleAsync(const std::int32_t receiver, const char* id, const char* command, const char* info)
{
    if (core::Stage::index_ == receiver)
        core::Stage::stage_->Handle(id, command, info);
}
