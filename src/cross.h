//
//  interface.h
//  cross
//
//  Created by Ali Asadpoor on 1/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_INTERFACE_H
#define CORE_INTERFACE_H

#include <cstdint>
#include <functional>
#include <vector>

namespace cross
{
extern "C"
{
    void Begin();
    void End();
    void Create();
    void Destroy();
    void Start();
    void Stop();
    void Restart();
    void Escape();
    void Handle(const char* id, const char* command, const char* info);
    void HandleAsync(const std::int32_t receiver, const char* id, const char* command, const char* info);
    void FeedUri(const char* uri, std::function<void(const std::vector<unsigned char>&)>&& consume);
}
}

#endif //CORE_INTERFACE_H
