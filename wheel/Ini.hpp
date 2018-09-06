#ifndef __IWTBAM_INI_HPP
#define __IWTBAM_INI_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "util.hpp"

#define TAB(n) (std::string(4*n, ' '))


namespace iwtbam {

struct Item
{
    Item(std::string key, std::string value):
        key(key), value(value)
    {};

    Item(std::string str)
    {
        parseItem(str);
    }

    Item() = default;
    Item(const Item& other) = default;
    Item(Item&& other) = default;


    template<class Stream>
    friend Stream& operator << (Stream& os, const Item& item)
    {
        os<<item.key<<" = "<<item.value<<std::endl;
        return os;
    }

    void parseItem(std::string str)
    {
        auto iterPos = std::distance(str.begin(), std::find(str.begin(), str.end(), '='));
        key = iwtbam::strip(str.substr(0, iterPos));
        value = iwtbam::strip(str.substr(iterPos + 1, str.size()));
    }

    std::string key;
    std::string value;
};



class Group
{
public:
    Group(std::string groupName, std::vector<Item>&& container = std::vector<Item>()):
        groupName(groupName), _container(std::move(container))
    {};

    Group() = default;
    Group(const Group& group) = default;
    Group(Group&& group) = default;

    Item& operator [](std::string key)
    {
        for(auto iter = _container.begin(); iter != _container.end();iter++)
        {
            if(iter->key== key)
                return *iter;
        }
    }

    void append(const Item& item)
    {
        this->_container.push_back(item);
    }

    void clear()
    {
        std::vector<Item>().swap(this->_container);
    }


    std::size_t size()
    {
        return this->_container.size();
    }

    template<class Stream>
    friend Stream& operator << (Stream& os, const Group& group)
    {
        if(group.groupName != std::string())
            os <<"["<<group.groupName<<"]"<<std::endl;
        
        for(auto item:group._container)
        {
            os << item;
        }

        os<<std::endl;
        return os;
    }

public:
     std::string groupName;

private:
   
    std::vector<Item> _container;

};

enum class IOState
{
    readOnly = 0x01,
    writyOnly = 0x10,
    all = 0x11
};


class Ini
{
public:
    Ini(std::initializer_list<Group> contents):
        _container(contents.begin(), contents.end())
    {}

    Ini(const std::string& filename)
    {
        read(filename);
    };

    Group& operator[](std::string groupName)
    {
        for(auto iter = _container.begin(); iter != _container.end(); iter++)
        {
            if(iter->groupName == groupName)
                return *iter;
        }
    }

    template<class Stream>
    friend Stream& operator << (Stream& os, const Ini& ini)
    {
        for(auto group:ini._container)
        {
            os<<group;
        }
        return os;
    }

    void read(const std::string& filename)
    {
        std::ifstream in(filename);
        std::string line;

        std::string curGroupName = std::string();
        Group curGroup(curGroupName);
        
        while(getline(in, line))
        {
            std::string temp = iwtbam::strip(line);            
            if(!temp.size())
                continue;
            
            if(temp.at(0) == '[')
            {
                if(*(temp.end() - 1)==']')
                {
                    curGroupName = std::string(temp.begin()+1, temp.end()-1);
                    
                    if(curGroup.size())
                    {
                        this->_container.push_back(curGroup);
                        curGroup.clear();
                    }
                    curGroup.groupName = curGroupName;
                }
            }
            else
            {
                Item item(temp);
                curGroup.append(item);
            }
        }

        if(curGroup.size())
            this->_container.push_back(curGroup);
    }
    void write(const std::string& filename)
    {
        std::ofstream outfile(filename);
        outfile << *this;
    }

private:
    std::vector<Group> _container;
};



}
#endif //