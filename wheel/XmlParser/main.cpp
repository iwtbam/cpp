#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "xml.hpp"
#include "strings/strings.hpp"

using namespace std;

using namespace iwtbam;

int main(int argc, char** argv)
{
    auto* parser = xml::XmlParser::Instance();
    xml::XmlNode root = parser->Parse("test.txt");


    cout << root.lable << endl;
    cout << root.value << endl;

    for(xml::XmlNode node:root.children)
    {
        cout << node.lable << endl;
    }
    


    return 0;
}