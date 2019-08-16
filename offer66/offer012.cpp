#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void swap(int& x, int& y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    
    int InversePairs(vector<int> data) {

        long long number = 0;
        
        // for(int i = 0; i < data.size() - 1; i++)
        // {
        //     for(int j = 0; j < data.size() -1 - i; j++)
        //     {
        //         if(data.at(j) > data.at(j+1))
        //         {
        //             swap(data.at(j+1), data.at(j));
        //             number = (number + 1) % 1000000007;
        //         }
        //     }
        // }

        sort(data.begin(), data.end(), [&](int a, int b)-> bool{
            if(a > b)
                number = (number+ 1) % 1000000007;

            return a < b; 
        });

        for(int i = 0; i< data.size();i++)
            cout << data.at(i) << " ";
        cout << endl;
        
        return number;
    }
};

int main()
{
    vector<int> iv = {1,2,3,4,5,6,7,0};
    Solution s;
    int number = s.InversePairs(iv);
    std::cout << number << std::endl;
}