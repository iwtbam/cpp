// 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
// 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>();
    }
};


int main()
{
    return 0;
}