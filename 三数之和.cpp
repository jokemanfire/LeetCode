#include"global.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<vector<int>,int> mHashmap;
        sort(nums.begin(), nums.end());
        vector<vector<int>> twoSum;
        for (int i = 0;i<nums.size()&& nums[i] <= 0; i++)
        {
            for (int j = i + 1; j < nums.size() ; j++)
            {
                if (nums[j] > 0&& nums[j] > -nums[i])
                {
                    break;
                }
                int sum = 0;
                vector<int> temp;
                sum = nums[i] + nums[j];
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(j);
                twoSum.push_back(temp);
            }
        }
        for (int k = 0; k < twoSum.size(); k++)
        {
            if (find(nums.begin() + twoSum[k][2], nums.end(), -(twoSum[k][0] + twoSum[k][1])) != nums.end())
            {
                vector<int> temp ;
                temp.push_back(twoSum[k][0]);
                temp.push_back(twoSum[k][1]);
                temp.push_back(-(twoSum[k][0] + twoSum[k][1]));
                sort(temp.begin(), temp.end());
                mHashmap[temp] = 1;
            }
        }
        for (auto i = mHashmap.begin(); i != mHashmap.end(); i++)
        {
            result.push_back(i->first);
        }
        return result;

    }
};

int main()
{
    vector<int> nums = { 0,0,0 };
    Solution().threeSum(nums);
}