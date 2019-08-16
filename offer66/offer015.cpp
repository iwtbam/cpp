
#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
    
    int bin_search(const vector<int>& array, int target,int low = 0 , int* pos = nullptr)
    {
        int high = array.size() -1;
        int mid = -1;

        // cout << "-----------" << endl;
        
        while(mid==-1 && low <= high)
        {
            mid = ( low + high)/2;
            // cout << low << " "<<mid << " " << high << " "<<array.at(mid) << endl;
            
            int ele = array.at(mid);
            
            if(target > ele)
                low = mid + 1, mid = -1;
            else if(target < ele)
                high = mid - 1, mid = -1;
        }
        
        if(pos)
            *pos = (mid!=-1 ? mid : high);
        
        return mid;
    }
    
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        
        int half = sum / 2;
        int pos;
        bin_search(array, half, 0, &pos);
        
        pair<int, int> p;
        
        int mul_result = __INT_MAX__;

        cout << pos << endl;
        
        for(int i = 0; i<=pos; i++)
        {
            int other = sum - array.at(i);

            int isFind = bin_search(array, other, pos + 1);
            
            // cout << other << " " << isFind << 

            if( isFind!=-1 && other * array.at(i) < mul_result)
            {
                mul_result = other * array.at(i);
                p.first = array.at(i);
                p.second = other;
            }           
        }
        
        if(p.first ==0 && p.second == 0)
            return vector<int>();
        return vector<int>{p.first, p.second};
    }
};


int main()
{

    vector<int> iv = {1,2,4,7,11,16};
    Solution s;
    
    vector<int> pv = s.FindNumbersWithSum(iv, 10);

    cout << pv[0] << " "<< pv[1] << endl;

    return 0;
}