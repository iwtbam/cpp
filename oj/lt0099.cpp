#include <vector>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution{
public:
    void recoverTree(TreeNode* root){
        if(root)
        {
            recoverTree(root->left);

            recoverTree(root->right);
        }
    }

    int recoverTreeHelper(TreeNode* root){
        if(root)
        {
            int leftV = recoverTree(root->left);
            int rightV = recoverTree(root->Val);
        }
    }
};