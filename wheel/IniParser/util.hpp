#ifndef __IWTBAM_UTIL_HPP
#define __IWTBAM_UTIL_HPP

#include <string>
#include <cctype>

namespace iwtbam {

std::string strip(std::string oldStr)
{
    std::string::iterator leftIter, rightIter;
    for(leftIter = oldStr.begin();leftIter !=oldStr.end() && std::isspace(*leftIter);leftIter++);
    for(rightIter = oldStr.end() - 1; rightIter != leftIter && std::isspace(*rightIter); rightIter--);
    if(leftIter > rightIter)
        return std::string();
    std::string newStr(leftIter, rightIter+1);
    return std::move(newStr);
}

}
#endif //__IWTBAM_UTIL_HPP