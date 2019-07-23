//
//  import.h
//  cross
//
//  Created by Ali Asadpoor on 4/1/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_IMPORT_H
#define CORE_IMPORT_H

#include <string>

namespace bridge
{
    void OnRestart();
    void LoadWebView(const __int32_t sender, const __int32_t view_info, const char *html);
    void LoadImageView(const __int32_t sender, const __int32_t view_info);
    __int32_t* GetPixels();
    void ReleasePixels(__int32_t* const pixels);
    void RefreshImageView();
    void CallFunction(const char* function);
    std::string GetAsset(const char* key);
    std::string GetPreference(const char* key);
    void SetPreference(const char* key, const char* value);
    void PostThreadMessage(const __int32_t sender, const char* message);
}

#endif //CORE_IMPORT_H
