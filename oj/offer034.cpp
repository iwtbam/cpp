// 请实现两个函数，分别用来序列化和反序列化二叉树

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

template<typename T>
string toString(T val)
{
    stringstream ss;
    ss << val;
    return ss.str();
} 

class Solution {
public:

    void Serialize(TreeNode *root, std::string& str) {
        if(!root)
            return;
        str.append(toString(root->val));
        str.push_back('(');
        Serialize(root->left, str);
        str.push_back(',');
        Serialize(root->right, str);
        str.push_back(')');    
    }

    char* Serialize(TreeNode* root)
    {
        string serial_str;
        Serialize(root, serial_str);
        char* p = new char[serial_str.size()];
        strcpy(p, serial_str.c_str());
        return p;
    }

    TreeNode* Deserialize(char *pstr) { 

        string str1 = {pstr};
        for(int i = 0; i < str1.size(); i++)
            str1[i] = pstr[i];

        if(!str1.size())
            return nullptr;
        cout << str1 << endl;
        stack<TreeNode*> ts;
        bool isLeft = true;
        int i = 0;
        for(; str1[i]>='0' && str1[i]<='9';i++);
        TreeNode* root = new TreeNode(atoi(str1.substr(0, i).c_str()));
        TreeNode* child,  *parent;

        ts.push(root);
        
        for(; i < str1.size(); i++)
        {
            
            if(pstr[i] == '(')
                isLeft = true;
            else if(pstr[i] == ',')
            {
                isLeft = false;
            }
            else if(pstr[i]==')')
            {
                ts.pop();
            }
            else
            {
                int j = i+1;
                for(;str1[j]>='0'&&str1[j]<='9';j++);
                child = new TreeNode(atoi(str1.substr(i, j).c_str()));
                i = j - 1;
                parent = ts.top();
                
                if(isLeft)
                    parent->left = child;
                else
                    parent->right = child;
                
                if(child)
                    ts.push(child);
            }
        }

        return root;
    }
};

int main()
{
    TreeNode* p = new TreeNode(421);
    TreeNode* p1 = new TreeNode(422);
    TreeNode* p2 = new TreeNode(333);
    TreeNode* p3 = new TreeNode(4);
    TreeNode* p4 = new TreeNode(425);
    TreeNode* p5 = new TreeNode(612);
    TreeNode* p6 = new TreeNode(721);
    TreeNode* p7 = new TreeNode(548);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    p3->right = p6;
    p5->left = p7;

    Solution s;
    char * str1 = s.Serialize(p);


    TreeNode* root = s.Deserialize(str1);
    char* str2 = s.Serialize(root);
    cout << str2 << endl;

    delete p;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;

    return 0;
}