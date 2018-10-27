
// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

#include <vector>
#include <algorithm>

using namespace std;

//376K 3ms
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:

    std::vector<std::vector<int>> result;

    vector<int> FindPath(TreeNode* root, std::vector<int> path, int expectNumber){
        
        path.push_back(root->val);
        if(root->left == nullptr && root->right==nullptr && expectNumber == root->val)
        {
            result.push_back(path);
        }
        
        if(root->left != nullptr)
            FindPath(root->left, path, expectNumber - root->val);
        if(root->right !=nullptr)
            FindPath(root->right, path, expectNumber - root->val);
    };

    vector<vector<int>> FindPath(TreeNode* root, int expectNumber){
        if(root == nullptr)
            return result;
        FindPath(root, std::vector<int>(), expectNumber);
        sort(result.begin(), result.end(), [](std::vector<int> left, 
            std::vector<int> right)->bool { return left.size() > right.size();});
        return result;
    }
};

int main()
{
    return 0;
}