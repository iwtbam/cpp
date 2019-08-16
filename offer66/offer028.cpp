#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int pos = -1;
        int max = -0x3f3f3f3f;
        
        vector<int> iv;
        
        for(int i = 0; i <= num.size() - size; i++)
        {
            if(pos >= i)
            {
                if(num.at(i + size - 1)>=max)
                {
                    pos = i + size - 1;
                    max = num.at(i + size - 1);
                }
            }
            else
            {
                max = -0x3f3f3f3f;
                pos = -1;
                for(int j = i; j < i + size;j++)
                {
                    if(num.at(j)>=max)
                    {
                        max = num.at(j);
                        pos = j;
                    }
                }
            }
            cout << max << " ";
            iv.push_back(max);
        }
        cout << endl;
        return iv;
    }
};

int main()
{
    vector<int> v = { 2,3,4,2,6,2,5,1};
    Solution s;
    s.maxInWindows(v, 3);
    return 0;
}

