#include <string>
#include <vector>
using namespace std;

//2019-06-15:22-27 回溯的标签 回溯超时服了

#define S2

#if defined(S1)
//回溯

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> visited(n, 0);
        string res;
        int step = 0;
        helper(res, visited, n, k, step);
        return res;
    }
    
    bool helper(string& record, vector<bool>& visited, int n, int k, int& step)
    {
        
        if(record.size() == n)
        {
            step++;
            if(step == k)
                return true;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            record.push_back(i+'1');
            visited[i] = 1;
            if(helper(record, visited, n, k, step))
                return true;
            visited[i] = 0;
            record.pop_back();
        }
        
        return false;
    }
};

#else

#endif

int main()
{
    string t;
    
    return 0;
}