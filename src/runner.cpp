//
//  runner.cpp
//  cross
//
//  Created by Ali Asadpoor on 7/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#include "runner.h"

#include <sstream>


core::Runner::Runner(__int32_t view_info, __int32_t image_width)
    : run_{true}
    , step_{false}
    , dpi_{0}
    , width_{0}
    , height_{0}
    , order_rgba_{0}
    , touch_x_{0.0f}
    , touch_y_{0.0f}
    , frame_lenght_{0}
{
    SetHandlers();
    worker_ = std::thread([this, index = index_]()
    {
        {
            std::unique_lock<std::mutex> lock_condition(lock_step_);
            condition_step_.wait(lock_condition, [this]() { return step_ || !run_; });
            if (!run_)
                return;
        }
        auto frame_time = std::chrono::steady_clock::now();
        for(;;)
        {
            auto wait = frame_time - std::chrono::steady_clock::now();
            if (wait.count() <= 0)
            {
                frame_time += frame_lenght_ - wait;
                std::unique_lock<std::mutex> lock_condition(lock_step_);
                step_ = false;
                lock_condition.unlock();
                bridge::PostThreadMessage(index, "body", "tick", "");
                lock_condition.lock();
                condition_step_.wait(lock_condition, [this](){ return step_ || !run_; });
                if (!run_)
                    break;
            }
            else
                std::this_thread::sleep_for(wait);
        }
    });
    bridge::LoadImageView(index_, view_info, image_width);
}

core::Runner::~Runner()
{
    lock_step_.lock();
    run_ = false;
    lock_step_.unlock();
    condition_step_.notify_all();
    worker_.join();
}

void core::Runner::Tick()
{
    __uint32_t* pixels = bridge::GetPixels();
    Step(pixels);
    bridge::ReleasePixels(pixels);
    bridge::RefreshImageView();
    lock_step_.lock();
    step_ = true;
    lock_step_.unlock();
    condition_step_.notify_all();
}

void core::Runner::SetHandlers()
{
    handlers_["body"] = [&](const char* command, const char* info)
    {
        if (std::strlen(command) == 0)
            return;
        else if (std::strcmp(command, "tick") == 0)
            Tick();
        else if (std::strcmp(command, "ready") == 0)
            Run(info);
        else if (std::strcmp(command, "touch-begin") == 0)
            Touch(1, info);
        else if (std::strcmp(command, "touch-move") == 0)
            Touch(2, info);
        else if (std::strcmp(command, "touch-end") == 0)
            Touch(3, info);
    };
}

void core::Runner::Run(const char* dimensions)
{
    std::istringstream parser(dimensions);
    parser >> dpi_ >> width_ >> height_ >> order_rgba_;
    lock_step_.lock();
    step_ = true;
    lock_step_.unlock();
    condition_step_.notify_all();
    Initial();
}

void core::Runner::Touch(int action, const char* position)
{
    float x, y;
    std::istringstream parser(position);
    parser >> x >> y;
    switch (action)
    {
    case 1:
        TouchBegin(x, y);
        break;
    case 2:
        TouchMove(x, y);
        break;
    case 3:
        TouchEnd(x, y);
        break;
    }
    touch_x_ = x;
    touch_y_ = y;
}
