// 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请
// 写程序找出这两个只出现一次的数字。

#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;


//这个方法不是最优，可以通过位运算将这个题复杂度降到o(n)
class Solution {

public:
    int _num1;
    int _num2;

    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        
        map<int, int> record;
        
        for(int i = 0; i<data.size(); i++)
        {
            if(record.find(data.at(i))==record.end())
            {
                record[data.at(i)] = 0;
            }
            else
                record[data.at(i)]++;
        }
        
        vector<pair<int, int>> pv(record.begin(),record.end());
        sort(pv.begin(), pv.end(), [](pair<int, int> p1, pair<int, int> p2)->bool
             {
                return p1.second < p2.second; 
             });
        
        *num1 = pv[0].first;
        *num2 = pv[1].first;


        return;
    }
};

int main()
{
    vector<int> data = {2,4,3,6,3,2,5,5};
    Solution s;
    int p1, p2;
    s.FindNumsAppearOnce(data, &p1, &p2);
   
    cout << p1 << endl;
    // cout << *p2 << endl;
}