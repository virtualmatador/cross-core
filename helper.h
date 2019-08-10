//
//  helper.h
//  cross
//
//  Created by Ali Asadpoor on 8/7/19.
//  Copyright © 2019 shaidin. All rights reserved.
//

#ifndef core_helper_h
#define core_helper_h

#include <list>
#include <string>


namespace helper
{
    void Http(const char* url, std::list<std::pair<std::string, std::string>> & payload, const char* id, const char* command);
    std::string EscapeHtml(const char* text);
}

#endif // core_helper_h
