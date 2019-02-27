#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "xml.hpp"
#include "strings/strings.hpp"

using namespace std;

int main(int argc, char** argv)
{
    fstream in("test.txt");
    std::string content = {istreambuf_iterator<char>{in}, {}};
    // cout << content << endl;

    string pattern = iwtbam::xml::XmlParser::LABEL_PATTERN;
    regex r(pattern);


    using iwtbam::strings::strip;

    for(sregex_iterator it(content.begin(), content.end(),r), end_it {}; it!=end_it;it++)
    {
        auto attr_content = it->str(2);
        regex r2(iwtbam::xml::XmlParser::ATTRIB_PATTERN);
        for(sregex_iterator attr_it(attr_content.begin(), attr_content.end(),r2), attr_end_it; attr_it!=attr_end_it; attr_it++)
        {
            cout << strip(attr_it->str(1)) << endl;
            cout << strip(attr_it->str(2)) << endl;
        }
    }

    return 0;
}