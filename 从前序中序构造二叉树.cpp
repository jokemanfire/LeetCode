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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        else
        {
            TreeNode* root = new TreeNode;
            root->val = preorder[0];
            auto it_index = find(inorder.begin(), inorder.end(), root->val);
            preorder = { preorder.begin() + 1,preorder.end() };
            vector<int> new_inorder_left = { inorder.begin(),it_index };
            vector<int> new_inorder_right = { it_index + 1,inorder.end() };
            root->left = buildTree(preorder, new_inorder_left);
            root->right = buildTree(preorder, new_inorder_right);
            return root;
        }

    }
};

int main()
{
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    Solution().buildTree(preorder, inorder);
}