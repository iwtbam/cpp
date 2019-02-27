#include "strings.hpp"
#include <cctype>

namespace iwtbam { namespace strings {

    std::string strip(std::string oldStr)
    {
        auto iterL{oldStr.begin()}, iterR{oldStr.end()-1};
        for(;iterL!=oldStr.end()&&std::isspace(*iterL);iterL++);
        for(;iterR!=iterL&&std::isspace(*iterR);iterR--);
        if(iterL > iterR)
            return {};

        size_t off = iterL - oldStr.begin();
        size_t count = iterR - iterL + 1;
        return oldStr.substr(off, count);
    }

    std::string stripl(std::string oldStr)
    {
        auto iterL{oldStr.begin()};
        for(;iterL!=oldStr.end()&&std::isspace(*iterL);iterL++);
        size_t off = iterL - oldStr.begin();
        return oldStr.substr(off);
    }

    std::string stripr(std::string oldStr)
    {
        auto iterR{oldStr.rbegin()};
        for(;iterR!=oldStr.rend()&&std::isspace(*iterR);iterR++);
        size_t off = oldStr.size() - (iterR - oldStr.rend()) + 1;
        return oldStr.substr(off);
    }
}}