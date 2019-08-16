<<<<<<< HEAD
// LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,
// 2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,
// 看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,
// 小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 
// 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”
// (大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,
// 然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,
// 你可以认为大小王是0


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers ) {
        
        int num_of_king = {0};
        int min = 0x3f3f3f3f;
        int max = -0x3f3f3f3f;

        for(int i = 0; i< numbers.size(); i++)
        {
            if(numbers.at(i))
            {
                min = min > numbers.at(i) ? numbers.at(i) : min ;
                max = max < numbers.at(i) ? numbers.at(i) : max ;
            }
            else
                num_of_king++;
        }

        int dis = max - min + 1;
        if(numbers.size() - num_of_king <= dis && dis <= numbers.size())
            return true;
        return false;
    }
};

int main()
{
    return 0;
=======
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
>>>>>>> 92a234e0c8aaccb0856bb751c9b3b7269d789021
}