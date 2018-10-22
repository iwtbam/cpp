#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        
        vector<vector<int>> vv;

        if(pRoot==nullptr)
            return vv;
        
        deque<TreeNode*> q;
        q.push_back(pRoot);
        
        int level = 1;

        while(!q.empty())
        {
            int size = q.size();
            deque<int> iv;
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop_front();
                level % 2 ? iv.push_back(node->val):iv.push_front(node->val);
                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);
            }

            // for(int i = 0; i< iv.size();i++)
            //     cout << iv.at(i) << " ";
            // cout << endl;
            vv.push_back(vector<int>(iv.begin(), iv.end()));
            level++;
        }

        return vv;
    }
};

int main()
{
    TreeNode* p = new TreeNode(8);
    TreeNode* p1 = new TreeNode(6);
    TreeNode* p2 = new TreeNode(10);
    TreeNode* p3 = new TreeNode(5);
    TreeNode* p4 = new TreeNode(7);
    TreeNode* p5 = new TreeNode(9);
    TreeNode* p6 = new TreeNode(11);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    Solution s;
    s.Print(p);
    
    return 0;
}