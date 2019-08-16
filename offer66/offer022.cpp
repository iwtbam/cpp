// 请实现一个函数用来找出字符流中第一个只出现一次的字符。
// 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
// 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    
    vector<pair<char, int>> record;
    char first;

    void Insert(char ch)
    {
        first = '#';
        bool isFind = false;

        for(int i = 0; i < record.size(); i++)
        {
            if(ch == record.at(i).first)
            {
                record.at(i).second++;
                isFind = true;
            }
            if(record.at(i).second == 1 && first == '#')
                first = '#';   
        }

        if(!isFind)
        {
            record.push_back(pair<char, int>{ch, 1});
            if(first=='#')
                first = ch;
        }
    }
  

    char FirstAppearingOnce()
    {
        return first;
    }

};

int main()
{
    Solution s;
    s.Insert('g');
}