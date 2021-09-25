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
    void LoadWebView(const std::int32_t sender, const std::int32_t view_info, const char *html);
    void LoadImageView(const std::int32_t sender, const std::int32_t view_info, const std::int32_t image_width);
    std::uint32_t* GetPixels();
    void ReleasePixels(std::uint32_t* const pixels);
    void RefreshImageView();
    void CallFunction(const char* function);
    std::string GetAsset(const char* key);
    std::string GetPreference(const char* key);
    void SetPreference(const char* key, const char* value);
    void AsyncMessage(const std::int32_t sender, const char* id, const char* command, const char* info);
    void AddParam(const char* key, const char* value);
    void PostHttp(const std::int32_t sender, const char* id, const char* command, const char* url);
    void Exit();
}

#endif //CORE_IMPORT_H
