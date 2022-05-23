#include"global.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    for (int f = k + 1; f < nums.size(); f++)
                    {
                        if (nums[i] + nums[j] + nums[k] == nums[f])
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
int main()
{
    vector<int> a = { 28, 8, 49, 85, 37, 90, 20, 8 };
    Solution().countQuadruplets(a);
}