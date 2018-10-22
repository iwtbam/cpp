#include <cmath>
#include <string>

#include <iostream>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        
        int sum = 0;
        int bit = 1;
        for(auto iter = str.rbegin(); iter != str.rend(); iter++)
        {
            
            if(iter == str.rend() -1)
            {
                if(*iter == '+' || *iter == '-')
                {
                    if(*iter=='-')
                        bit = -1;
                     continue;

                }   
            }
            
            if( *iter >='0' && *iter <= '9')
                sum += (*iter - '0') * pow(10, iter - str.rbegin());
            else
            {
                sum = 0;
                break;
            }
        }
        
        return sum * bit;
    }
};

int main()
{
    Solution s;
    cout << s.StrToInt("+134")<< endl;
}