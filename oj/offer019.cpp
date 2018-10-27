
#include <iostream>
#include <vector>
#include <queue>

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
            
            queue<TreeNode*> q;
            vector<vector<int>> vv;
            q.push(pRoot);
            
            int node_size = q.size();
            
            vector<int> iv;
            
            while(q.size())
            {
                
                TreeNode* node = q.front();
                iv.push_back(node->val);                
                
                
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                
                node_size--;
                q.pop();
                
                if(!node_size)
                {
                    node_size = q.size();
                    vv.push_back(iv);
                    for(int i = 0; i < iv.size(); i++)
                        cout << iv.at(i) <<" ";
                    cout << endl;
                    vector<int>().swap(iv);
                }
                
            }
            return vv;
        }
    
};


int main()
{
    TreeNode* p = new TreeNode(1);
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(3);
    p->left = p1;
    p->right = p2;

    Solution s;
    s.Print(p);
}