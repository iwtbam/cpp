// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#if defined(S1)

// 超时
class Solution {
public:

    bool matchHelper(string s, int sindex, string p, int pindex)
    {
        if(sindex == s.size() && pindex == p.size())
            return true;

        if(pindex == p.size())
            return false;

        if(sindex == s.size())
            return p[pindex] == '*' ? matchHelper(s, sindex, p, pindex + 1) : false;

        if(p[pindex]!='*')
        {
            if(p[pindex]=='?')
                return matchHelper(s, sindex+1, p, pindex+1);
            else if(s[sindex]==p[pindex])
                return matchHelper(s, sindex+1, p, pindex+1);
            else
                return false;
        }
        else
        {
            for(int i = sindex; i <= s.size(); i++)
                if(matchHelper(s, i, p, pindex + 1))
                    return true;
        }
        return false;
    }

    bool isMatch(string s, string p) 
    {
        return matchHelper(s, 0, p, 0);   
    }
};
#else 
class Solution {
public:

    bool isMatch(string s, string p) 
    {
        vector<int> vec(s.size(), 0);
        return false;   
    }
};
#endif

int main()
{
    Solution s;
    bool r = s.isMatch("aa", "*");
    cout << r << endl;
    r = s.isMatch("aa", "a");
    cout << r << endl;
    r = s.isMatch("cb", "?a");
    cout << r << endl;
    r = s.isMatch("adceb", "*a*b");
    cout << r << endl;
    r = s.isMatch("acdcb", "a*c?b");
    cout << r << endl;
    r = s.isMatch("", "*");
    cout << r << endl;
    r = s.isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab","***bba**a*bbba**aab**b");
    cout << r << endl;
    return 0;
}