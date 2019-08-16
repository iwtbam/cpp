#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int num[10];
    
    void calc_num()
    {
        num[0] = 0;
        for(int i = 1; i < 10; i++)
            num[i] = 10* num[i-1] + pow(10, i-1);
    }

    Solution(){
        calc_num();
    }

    int len(int n)
    {
        int l = 1;
        while(n/10)
        {
            n /= 10;
            l++;
        }
        return l;
    }

    int NumberOf1Between1AndN_Solution(int n)
    {
        int l = len(n);
        int number = 0;


        for(int i = l - 1; i >= 0; i--)
        {
            int c = n / pow(10, i);
            n = n - pow(10, i) * c;
            number += num[i] * c + (c > 1? pow(10, i) : (n + 1) * c);
        }

        return number;
    }
};

int main()
{
    Solution s;
    int num1 = s.NumberOf1Between1AndN_Solution(13);
    int num2 = s.NumberOf1Between1AndN_Solution(55);

    cout << num1 << endl
         << num2 << endl;
    
}