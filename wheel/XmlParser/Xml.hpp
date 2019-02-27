#ifndef IWTBAM_XML_H
#define IWTBAM_XML_H


#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

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
        static XmlParser& Instance();
        XmlNode Parse(std::string file_path);
    private:
        XmlParser()=default;
        XmlNode ParseHelper(std::string content);
        
    public:
        static const std::string LABEL_PATTERN;
        static const std::string ATTRIB_PATTERN;
    };

    const std::string XmlParser::LABEL_PATTERN = "<(.+?) ((?:\\s|.)+?)>((?:\\s|.)*)</\\1\\s*>";
    const std::string XmlParser::ATTRIB_PATTERN = "(.+?)\\s*=\\s*\"(.+?)\"";

    XmlParser& XmlParser::Instance()
    {
        static XmlParser instance_;
        return instance_;
    }

    XmlNode  XmlParser::Parse(std::string file_path)
    {
        std::ifstream in(file_path);
        std::istreambuf_iterator<char> begin{in};
        std::string content{begin, {}};
        return node;
    }

    XmlNode ParseHelper(std::string content)
    {
        XmlNode node;
        for(int i = )
        return {};
    }

}
}

#endif