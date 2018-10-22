#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        
        vector<string> sv;
        
        int left = 0;
      
        for(int i = 0; i < str.size(); i++)
        {
            if(str.at(i) == ' ')
            {
                sv.push_back(str.substr(left, i - left));
                left = i + 1;
                cout<< sv.back() << endl;
            }
        }
        

        sv.push_back(str.substr(left, str.size() - left));
        string result = *sv.rbegin();

        for(auto iter = sv.rbegin() + 1; iter != sv.rend(); iter++)
        {
            result = result + " " + *iter;
        }

        return result;
        
    }
};

int main()
{
    string s1 = "student. a am I";
    Solution s;

    string r = s.ReverseSentence(s1);
    cout << r << endl;
}