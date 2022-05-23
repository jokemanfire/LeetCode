#include"global.h"
class Solution{
public:
    int minimumDifference(vector<int>&nums, int k) {
        sort(nums.begin(),nums.end());
        int minus = nums[k - 1] - nums[0];
        for (int i = 0; i < nums.size() - k +1; i++)
        {
            if (nums[i + k -1] - nums[i] < minus)
            minus = nums[i + k-1] - nums[i];
        }
        return minus;
    }
};

int main()
{
    vector<int> nums = { 9,4,1,7 };
    Solution().minimumDifference(nums,2);
}