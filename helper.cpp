//
//  helper.cpp
//  cross
//
//  Created by Ali Asadpoor on 8/7/19.
//  Copyright © 2019 shaidin. All rights reserved.
//

#include "bridge.h"
#include "stage.h"

#include "helper.h"

void helper::Http(const char* url, std::list<std::pair<std::string, std::string>> & params, const char* callback)
{
    for (const auto & param : params)
        bridge::AddParam(param.first.c_str(), param.second.c_str());
    bridge::PostHttp(core::Stage::index_, url, callback);
}

std::string helper::EscapeHtml(const char* text)
{
    std::string html;
    while (*text != '\0')
    {
        switch(*text)
        {
        case '&':  html.append("&amp;");
            break;
        case '\"': html.append("&quot;");
            break;
        case '\'': html.append("&apos;");
            break;
        case '<':  html.append("&lt;");
            break;
        case '>':  html.append("&gt;");
            break;
        default:   html.append(text, 1);
            break;
        }
        ++text;
    }
    return html;
}
