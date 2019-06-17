#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution{
public:
    void flatten(TreeNode* root){
        if(root)
        {
            flatten(root->left)
            
        }
    }
};