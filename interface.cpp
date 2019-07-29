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
    core::Stage::index_ = 0;
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
    life_cycle::Stop();
    ++core::Stage::index_;
    core::Stage::stage_.reset(nullptr);
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

void interface::Handle(const char* message)
{
    core::Stage::stage_->Handle(message);
}

void interface::HandleAsync(const __int32_t receiver, const char* message)
{
    if (core::Stage::index_ == receiver)
        core::Stage::stage_->Handle(message);
}
