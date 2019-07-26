//
//  runner.h
//  cross
//
//  Created by Ali Asadpoor on 7/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_RUNNER_H
#define CORE_RUNNER_H

#include "stage.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


namespace core
{
    class Runner : public Stage
    {
    private:
        std::thread worker_;
        std::mutex lock_step_;
        bool run_;
        bool step_;
        std::condition_variable condition_step_;

    protected:
        std::chrono::milliseconds frame_lenght_;
        __int32_t dpi_;
        __int32_t  width_;
        __int32_t  height_;
        float touch_x_;
        float touch_y_;

    public:
        Runner(__int32_t view_info, __int32_t image_width);
        ~Runner();
        void Run(const __int32_t dpi, const __int32_t width, const __int32_t height);
        void Tick();

    private:
        void SetHandlers();
        void Touch(int action, const char* position);

    protected:
        virtual void Initial() = 0;
        virtual void Step(__uint32_t* pixels) = 0;
        virtual void TouchBegin(float x, float y) = 0;
        virtual void TouchMove(float x, float y) = 0;
        virtual void TouchEnd(float x, float y) = 0;
    };
}

#endif //CORE_RUNNER_H