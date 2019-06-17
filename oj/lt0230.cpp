#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root)
        {
            kthSmallest(root->left, k);
            k--;
            if(k==0)
                return root->val;
            kthSmallest(root->right, k);
        }      
    }
};