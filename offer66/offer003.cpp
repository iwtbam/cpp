// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串
// abc,acb,bac,bca,cab和cba。


// 能过 复杂度太高 不建议

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:

    string result;
    string temp;
    vector<string> list;
    int vis[20];

    void dfs()
    {
        if(result.size() == temp.size())
        {
            list.push_back(result);
            cout << result << endl;
            return;
        }

        for(int i = 0; i<temp.size();i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                result.append(1, temp.at(i));
                dfs();
                vis[i] = 0;
                result.pop_back();
            }
        }
    }

    vector<string> Permutation(string str) {
        
        for(int i = 0; i < str.size(); i++)
        {
            if((str.at(i)>='a' && str.at(i)<='z') ||
               (str.at(i)>='A' && str.at(i)<='Z'))
            {
                temp.push_back(str.at(i));
            }
        }


        sort(temp.begin(), temp.end());
        memset(vis, 0, sizeof(vis));
        dfs();
        return list;
    }
};


int main()
{
    Solution s;
    auto list = s.Permutation("aab");
    // for(int s)
    return 0;
}
