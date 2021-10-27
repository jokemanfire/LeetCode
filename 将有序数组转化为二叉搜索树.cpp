#include"global.h"
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		int mid = (nums.size() - 1) / 2;
		TreeNode* root = new TreeNode;
		root->val = nums[mid];
	
		int left = 0;
		int right = nums.size() - 1;
	
		
		if (left < mid)
		{
			std::vector<int>::const_iterator first = nums.begin();
			std::vector<int>::const_iterator last = nums.begin() + mid;
			std::vector<int> tmpMsg(first, last);
			root->left = sortedArrayToBST(tmpMsg);
		}
		else
			root->left = nullptr;
		if (mid < right)
		{
			std::vector<int>::const_iterator first = nums.begin() + mid + 1;
			std::vector<int>::const_iterator last = nums.end();
			std::vector<int> tmpMsg2(first, last);
			root->right = sortedArrayToBST(tmpMsg2);
		}
		else
			root->right = nullptr;
		return root;
	}
};

int main()
{
	vector<int> nums = { -10,-3,0,5,9 };
	TreeNode* a = new TreeNode;
	a = Solution().sortedArrayToBST(nums);

	return 1;
}