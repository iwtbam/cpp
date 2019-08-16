
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同

#include <vector>
#include <iostream>

using namespace std;

// 376K 4ms
class Solution{
public:

    static bool VerifySquenceOfBST(vector<int> sequence)
    {

        if(sequence.size() <= 0)
            return false;

        if(sequence.size() <= 1)
            return true;

        int root = sequence.back();
        vector<int>::iterator iter = sequence.begin();

        for(;iter != sequence.end() && *iter < root; iter++);
        for(;iter != sequence.end() - 1 && *iter > root; iter++);

        if(iter == sequence.end() - 1)
            return VerifySquenceOfBST(std::vector<int>(sequence.begin(), iter)) && 
                   VerifySquenceOfBST(std::vector<int>(iter, sequence.end()));

        return false;
    }    
};

int main()
{
    std::vector<int> iv = {1,3,4,6,9,7,5};
    bool result = Solution::VerifySquenceOfBST(iv);
    std::cout << std::boolalpha << result << std::endl;
}