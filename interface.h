//
//  interface.h
//  cross
//
//  Created by Ali Asadpoor on 1/15/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_INTERFACE_H
#define CORE_INTERFACE_H

#include <stdint.h>


namespace interface
{
    void Begin();
    void End();
    void Create();
    void Destroy();
    void Start();
    void Stop();
    void Restart();
    void RunImageView(const __int32_t receiver, const __int32_t dpi, const __int32_t width, const __int32_t height);
    void Handle(const __int32_t receiver, const char *message);
}

#endif //CORE_INTERFACE_H
