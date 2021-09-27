//
//  import.h
//  cross
//
//  Created by Ali Asadpoor on 4/1/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_IMPORT_H
#define CORE_IMPORT_H

#include <cstdint>
#include <string>

namespace bridge
{
    void NeedRestart();
    void LoadView(const std::int32_t sender, const std::int32_t view_info, const char *html);
    void CallFunction(const char* function);
    std::string GetPreference(const char* key);
    void SetPreference(const char* key, const char* value);
    void AsyncMessage(const std::int32_t sender, const char* id, const char* command, const char* info);
    void AddParam(const char* key, const char* value);
    void PostHttp(const std::int32_t sender, const char* id, const char* command, const char* url);
    void Exit();
}

#endif //CORE_IMPORT_H
