#include <iostream>
#include <vector>
// #include <vect>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        vector<int> s;

        for(int i = 0, j = 0; i < pushV.size(); i++)
        {
            s.push_back(pushV.at(i));
            while(j < popV.size() && popV.at(j) == s.back())
            {
                s.pop_back();
                j++;
            }
        }

        return s.empty();        
    }
};

int main()
{
      
}