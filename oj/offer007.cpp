// 统计一个数字在排序数组中出现的次数

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        
        int low = 0;
        int high = data.size() -1;

        int mid =-1;

        while(mid == -1 && low <= high)
        {
            mid = (low + high) / 2;

            if(k > data.at(mid))
                low = mid + 1, mid = -1;
            else if(k < data.at(mid))
                high = mid - 1, mid = -1;
        }

        while(mid == -1 && low <= high)
        {
            mid = (low + high) / 2;

            if(k < data.at(mid))
                low = mid + 1, mid = -1;
            else if(k > data.at(mid))
                high = mid - 1, mid = -1;
        }

        int num = 0;
        cout << mid << endl;
        for(int i = mid; i < data.size() && data.at(i) == k ;i++, num++);
        cout << num<<endl;
        for(int i = mid - 1; i >=0 && data.at(i) == k; i--, num++);

        cout << num << endl;
        return num;
    }
};

int main()
{
    std::vector<int> data = {1,3,3,4,5,6,7,8,9,10,11,23};

    Solution s;
    int num = s.GetNumberOfK(data, 3);

    // cout << num << endl;  
    return 0;
}