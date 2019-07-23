//
//  pack.h
//  cross
//
//  Created by Ali Asadpoor on 4/11/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#ifndef CORE_PACK_H
#define CORE_PACK_H

#include <string>
#include <map>

namespace core
{
    class Pack : public std::map<std::string, std::string>
    {
    public:
        Pack();
        ~Pack();
        void Parse(const char *text);
        std::string Serialize();
        std::string Encode(const char *text);
        std::string Decode(const char *text);
    };
}

#endif //CORE_PACK_H
