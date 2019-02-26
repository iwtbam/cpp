#ifndef IWTBAM_XML_H
#define IWTBAM_XML_H


#include <vector>
#include <map>
#include <string>

namespace iwtbam {
namespace xml {

    struct XmlNode
    {
        std::string lable;
        std::map<std::string, std::string> attributes;
        std::string value;
        std::vector<XmlNode> children;
    };

    class XmlParser
    {
    public:

    private:
        std::string filepath_;
    };

}
}

#endif