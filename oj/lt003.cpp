#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define DEBUG
#undef DEBUG


#ifdef S1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(!s.size())
            return 0;

        int record[256];
        memset(record, 0, sizeof(record));
        int l = 0, i = 1, ml = 0, mr = 0;
        record[s[0]] = 1;
        for(;i < s.size(); i++)
        {
            if(record[s[i]])
            {
                #ifdef DEBUG
                    cout << l << ends << i << ends << ml << ends << mr << endl;
                #endif
                if(i - l > mr - ml + 1)
                {
                    mr = i - 1; 
                    ml = l;
                }

                l = i;    
                
                memset(record, 0, sizeof(record));
                record[s[i]] = 1;
            }
            else
                record[s[i]] = 1;
        }

        if(i - l > mr - ml + 1)
            return i - l;
        // cout << ml << ends << mr << endl;

        return mr - ml + 1;
    }
};

#else
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        
    }
};
#endif

int main()
{
    Solution s;
    int c = s.lengthOfLongestSubstring("abcabcbb");
    cout << c << endl;
    c = s.lengthOfLongestSubstring("bbbbb");
    cout << c << endl;
    c = s.lengthOfLongestSubstring("pwwkew");
    cout << c << endl;
    return 0;
}