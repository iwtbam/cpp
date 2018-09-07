#include <vector>
#include <map>

namespace iwtbam {


class XMlChecker
{

};

class XMlParse
{

};

class XMlNode
{
public:

private:
    std::vector<XMlNode> child;
    std::map<std::string, std::string> attrib;
};



}