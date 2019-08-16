struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return preorder(root, key);
    }

    TreeNode* preorder(TreeNode* root, int key)
    {
        if(root)
        {
            if(root->val == key)
                return root;
            
            TreeNode* res = preorder(root->left, key);
            if(res==nullptr)
                res = preorder(root->right, key);
            return res;
        }

        return nullptr;
    }
};