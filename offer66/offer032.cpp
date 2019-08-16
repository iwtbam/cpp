// 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
// 他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟
// 有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他
// 就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列?
//  Good Luck!

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:

    template<typename T1, typename T2>
    bool calc(int& x, int& y, T1&& r1, T2&& r2, vector<vector<int>>& vv)
    {
        if((r1 + r2)%2 == 0)
            return false;
        
        x = (r1 + r2 - 1) / 2;
        y =  r2 - x;

        if( x <= 0 || y <= 0 || x == y)
            return false;

        vector<int> iv;

        for(int i = y; i <= x; i++)
            iv.push_back(i);
        vv.push_back(iv);
        
        return true;
    }

    vector<vector<int> > FindContinuousSequence(int sum) {
            
        int lo, hi, a, b;

        vector<vector<int>> vv;
        for(int i = 2; i <= static_cast<int>(sqrt(sum)); i++)
        {
            if(sum % i)
                continue;

            a = i;
            b = sum / i;

            b % 2 ? calc(hi, lo, a*2, b, vv):0;
            calc(hi, lo, a, b * 2, vv);
            
            // if(a == b)
            //     continue;

            // a % 2 ? calc(hi, lo, b*2, a, vv):0;
            // calc(hi, lo, b, a*2, vv);
        }

        sort(vv.begin(), vv.end(), [](vector<int> iv1, vector<int> iv2)->bool{
            return iv1.at(0) < iv2.at(0);
        });

        for(auto iv : vv)
        {
            for(auto e : iv)
            {
                cout << e<< ends;
            }
            cout << endl;
        }

        return vv;
    }
};

int main()
{
    Solution s;
    s.FindContinuousSequence(200);
}