#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Solution {
public:
    
    inline bool isNum(char c)
    {
        return c >= '0' && c<='9';
    }
    
    bool isNumeric(char* string)
    {
        if(!strlen(string))
            return false;
        
        int start = 0, state = 0x0;
        
        if(string[0]=='+' || string[0]=='-')
            start = 1;

        cout << string << endl;
        
        for(int i = start; string[i] ; i++)
        {
            char c = string[i];

            // cout << (c - '\0') << endl;


            if(isNum(c))
                state = state & 0xfe;
            else
            {
                if(c=='E' || c == 'e')
                    state = state | 0x03;
                else if(c=='.')
                {
                    // cout << hex << state << endl;

                    if(state & 0x02)
                        return false;
                    state = state | 0x02;
                }
                else if( c== '+' || c=='-')
                {
                    if(!(state & 0x01))
                        return false;
                    state = state & 0xfe;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    char*  pstr = { "-.123" };
    bool r = s.isNumeric(pstr);

    cout << r << endl;
    
    return 0;
}

