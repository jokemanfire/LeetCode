#include"global.h"
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> result;
        vector<int> r;
        int threald = nums.size() / 3;
        for (int i = 0; i < nums.size(); i++)
        {
            result[nums[i]] ++;
        }
        for (auto i : result)
        {
            if (i.second > threald)
                r.push_back(i.first);
        }
        return r;
    }
};

int main()
{
    vector<int> nums = { 4, 5, 3, 4, 4, 1, 0, -1, -2, 4, 6, 7, 8, 4 };
    Solution().majorityElement(nums);
}