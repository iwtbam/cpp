#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int bits = 1;
        int sum = 0;
        int co = 0;
        
        for(int i = 0; i< 32; i++)
        {
            int bit1 = (num1 & bits << i);
            int bit2 = (num2 & bits << i);
            int res = bit1 ^ bit2 ^ co;   

            co = ((bit1 & bit2) | (bit1 & co) | (bit2 & co)) << 1;
            sum |= res;
        }
        
        return sum;
    }
};

// public class Solution {
//     public int Add(int num1,int num2) {
//         while (num2!=0) {
//             int temp = num1^num2;
//             num2 = (num1&num2)<<1;
//             num1 = temp;
//         }
//         return num1;
//     }
// }
int main()
{
    Solution s;
    int r = s.Add(7352,326);
    std::cout << r << endl;
}