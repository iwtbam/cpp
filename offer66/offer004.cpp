#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        
        int max_sub_sum = -__INT32_MAX__;
        int sub_sum = 0;
        
        for(int i = 0; i< array.size();i++)
        {
            sub_sum += array.at(i);
            if(sub_sum >= 0)
                max_sub_sum = max_sub_sum > sub_sum ? max_sub_sum : sub_sum;
            else
                sub_sum = 0;
        }

    }
};

