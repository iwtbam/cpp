#ifndef IWTBAM_XML_H
#define IWTBAM_XML_H


#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <regex>
#include "strings/strings.hpp"


namespace iwtbam {
namespace xml {

    struct XmlNode
    {
        std::string lable;
        std::map<std::string, std::string> attributes;
        std::string value;
        std::vector<XmlNode> children;
    };


    class UnCopyable
    {
    public:
        UnCopyable()=default;
    private:
        UnCopyable(const UnCopyable&)=delete;
        UnCopyable& operator=(const UnCopyable&)=delete;
        UnCopyable(const UnCopyable&&)=delete;
        UnCopyable& operator=(const UnCopyable&&)=delete;
    };

    class XmlParser:public UnCopyable
    {

    public:
        using vector_xmlnode_t = std::vector<XmlNode>;
    public:
        static XmlParser* Instance();
        XmlNode Parse(std::string file_path);
    private:
        XmlParser()=default;
        std::vector<XmlNode> ParseHelper(std::string content);
    
    public:
        static const vector_xmlnode_t  XML_NODE_NIL;
        static const std::string LABEL_PATTERN;
        static const std::string ATTRIB_PATTERN;
    };

    const std::string XmlParser::LABEL_PATTERN = "<(.+?)>((?:\\s|.)*)</.+?>";
    const std::string XmlParser::ATTRIB_PATTERN = "(.+?)\\s*=\\s*\"(.+?)\"";
    const XmlParser::vector_xmlnode_t XmlParser::XML_NODE_NIL = {};
    XmlParser* XmlParser::Instance()
    {
        static XmlParser instance_;
        return &instance_;
    }

    XmlNode  XmlParser::Parse(std::string file_path)
    {
        std::ifstream in(file_path);
        std::istreambuf_iterator<char> begin{in};
        std::string content{begin, {}};
        XmlParser::vector_xmlnode_t nodes = ParseHelper(content);       
        if(nodes.size())
            return nodes[0];
        return {};
    }

    XmlParser::vector_xmlnode_t XmlParser::ParseHelper(std::string content)
    {
        // std::cout << content << std::endl;

        XmlParser::vector_xmlnode_t children = {};
        std::regex r(XmlParser::LABEL_PATTERN);
        for(std::sregex_iterator it(content.begin(), content.end(),r), end_it {}; it!=end_it;it++)
        {
            XmlNode node;
            node.lable = it->str(1);
            auto attr_content = it->str(2);
            node.value = it->str(3);
            std::cout << node.lable << std::endl;
            std::cout << node.value << std::endl;
            std::regex r2(iwtbam::xml::XmlParser::ATTRIB_PATTERN);
            for(std::sregex_iterator attr_it(attr_content.begin(), attr_content.end(),r2), attr_end_it; attr_it!=attr_end_it; attr_it++)
            {
                auto key = strings::strip(attr_it->str(1));
                auto value = strings::strip(attr_it->str(2));
                node.attributes[key] = value; 
            }
            node.children = ParseHelper(node.value);
            children.push_back(node);
        }

        if(children.empty())
            return XmlParser::XML_NODE_NIL;
        return children;

    }

}
}

#endif