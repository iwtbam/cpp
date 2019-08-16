// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
// 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

#include <string>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        
        if(str.size()==0)
            return 0;
        

        map<char, int> pos;

        for(int i = 0 ; i < str.size() ; i++)
        {
            if(pos.find(str.at(i))==pos.end())
            {
                pos[str.at(i)] = i;
            }
            else
                pos[str.at(i)] = -1;
        }

        vector<pair<char, int>> pv(pos.begin(), pos.end());

        sort(pv.begin(), pv.end(), [](pair<char, int> p1, pair<char, int> p2)->bool
        {
            if(p1.second == -1)
                return false;
            
            if(p2.second == -1)
                return true;

            return p1.second < p2.second;
        });      

        auto first = pv.begin();

        return first->second;
    }
};

int main()
{
    return 0;
}