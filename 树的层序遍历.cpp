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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >result;
        queue<TreeNode* > res;
        res.push(root);
        res.push(nullptr);
        vector<int>  Oneflat;
        while (!res.empty())
        {
            TreeNode* temp = res.front();

            res.pop();

            if (temp == nullptr)
            {
                result.push_back(Oneflat);
                Oneflat.clear();
                if (!res.empty())
                    res.push(nullptr);
            }
            else
            {
                cout << temp->val << endl;
                Oneflat.push_back(temp->val);
                if (temp->left != nullptr)
                    res.push(temp->left);
                if (temp->right != nullptr)
                    res.push(temp->right);
            }

        }
        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode;
    Solution().levelOrder(root);
}