#include <vector>
#include <iostream>

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
// 即输出P%1000000007 

using namespace std;



class Solution {
public:

    int num = 0;

    int InversePairs(vector<int> data) {
        num = 0;
        dvide(data, 0, data.size()-1);
        cout << num << endl;

        return num;
    }

    void dvide(vector<int>& data, int low, int high)
    {
        if(low>=high)
            return;
        int middle = (low + high)/2;
        dvide(data, low, middle);
        dvide(data, middle+1, high);
        merge(data, low, middle, high);
    }

    void merge(vector<int>& data, int low, int middle, int high)
    {
        vector<int> temp;
        int i = low, j = middle+1;
        while(i<=middle && j <= high)
        {
            if(data.at(i) <= data.at(j))
                temp.push_back(data.at(i++));
            else
            {
                temp.push_back(data.at(j++));
                num += (middle - i) + 1;
            }
        }

        while(i<=middle)
            temp.push_back(data.at(i++));
        while(j<=high)
            temp.push_back(data.at(j++));
        
        i = 0;
        while(i<temp.size())
            data[low++] = temp[i++];
    }
};

int main()
{
    vector<int> data = {1,2,4,5,3,6,7,0};
    Solution s;
    s.InversePairs(data);
}