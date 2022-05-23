#include"global.h"

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> Result;
		for (int i = 0; i < pow(2, nums.size()); i++)
		{
			int temp = i;
			vector<int> One;
			int count = 0;
			while (temp != 0)
			{
				if (temp & 1 == 1)
					One.push_back(nums[count]);
				count++;
				temp >>= 1;
			}
			Result.push_back(One);
		}
		return Result;
	}
};
int main()
{
	vector<int>nums = { 1,2,3 };
	Solution().subsets(nums);
}