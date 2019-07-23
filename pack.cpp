//
//  pack.cpp
//  cross
//
//  Created by Ali Asadpoor on 4/11/19.
//  Copyright © 2019 Shaidin. All rights reserved.
//

#include "pack.h"

#include <sstream>
#include <iomanip>

core::Pack::Pack()
{
}

core::Pack::~Pack()
{
}

void core::Pack::Parse(const char *text)
{
    std::istringstream ts(text);
    std::string key, value;
    while(std::getline(ts, key, '='))
    {
        std::getline(ts, value, '&');
        (*this)[Decode(key.c_str())] = Decode(value.c_str());
    }
}

std::string core::Pack::Serialize()
{
    std::string serialized;
    for (auto & kv : *this)
    {
        serialized += Encode(kv.first.c_str());
        serialized += '=';
        serialized += Encode(kv.second.c_str());
        serialized += '&';
    }
    return serialized;
}

std::string core::Pack::Encode(const char* text)
{
    std::ostringstream result;
    result.setf(std::ios::uppercase);
    for (int i = 0; text[i] != 0; ++i)
    {
        if (std::isalnum(text[i]))
            result << text[i];
        else
            result << '%' << std::setw(2) << reinterpret_cast<const unsigned char &>(text[i]);
    }
    return result.str();
}

std::string core::Pack::Decode(const char* text)
{
    std::ostringstream result;
    for (int i = 0; text[i] != 0; ++i)
    {
        if (text[i] != '%')
            result << text[i];
        else
        {
            if (text[i + 1] != 0 && text[i + 2] != 0)
            {
                char num[3] = {text[i + 1], text[i + 2], '\0'};
                unsigned char c = static_cast<unsigned char>(std::stoul(num, nullptr, 16));
                if (c != 0)
                    result << reinterpret_cast<char&>(c);
            }
            i += 2;
        }
    }
    return result.str();
}
