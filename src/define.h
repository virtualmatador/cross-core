//
//  progress.h
//  cross
//
//  Created by Ali Asadpoor on 7/16/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_DEFINE_H
#define CORE_DEFINE_H

#include <stdint.h>


namespace core
{
    enum class VIEW_INFO: std::int32_t
    {
        Default = 0x00000000,
        Portrait = 0x00000001,
        Landscape = 0x00000002,
        ScreenOn = 0x00000004,
        CloseMenu = 0x00000008,
        AudioNoSolo = 0x00000010,
    };
}

#endif //CORE_DEFINE_H
