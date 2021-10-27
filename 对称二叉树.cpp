#include"global.h"


 struct TreeNode {
 int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root != nullptr)
        {
            vector<int> a = GetData(root->left);
            vector<int> b = GetData(root->right);
        }

    }

    vector<int> GetData(TreeNode* root)
    {
        vector<int> result;
        queue<TreeNode* > Nodes;
        if (root != nullptr)
            Nodes.push(root);
        while (Nodes.size() != 0)
        {
            result.push_back(root->val);
            if (root->left != nullptr)
                Nodes.push(root->left);
            if (root->right != nullptr)
                Nodes.push(root->right);

        }
        return result;
    }
};



int main()
{
    TreeNode* root = new TreeNode();
    vector<int> d = {1, 2, 2, 3, 4, 4, 3};
    InitNodes(root,d);
    Solution().isSymmetric(root);
}