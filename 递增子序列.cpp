#include"global.h"

class Solution {
public:
	vector<vector<int>>Result;
	vector<int> Now;
	map<vector<int>, bool> Flags;
	void GetOneData(vector<int>& nums, int index)
	{
		if (index >= nums.size())
		{
			if (Now.size() >= 2 && Flags.count(Now)==0)
			{
				Result.push_back(Now);
				Flags[Now] = true;
			}
		}
		else
		{
			bool FLag = false;
			if (Now.size() > 0 && nums[index] >= Now.back())
			{
				FLag = true;
				Now.push_back(nums[index]);
			}
			
			else if (Now.size() == 0)
			{
				FLag = true;
				Now.push_back(nums[index]);
			}
			GetOneData(nums, index + 1);
			if(FLag)
			Now.pop_back();
			GetOneData(nums, index + 1);
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		GetOneData(nums, 0);
		return Result;
	}
};

int main()
{
	vector<int> a = { 4,4,3,2,1 };
	Solution().findSubsequences(a);
}