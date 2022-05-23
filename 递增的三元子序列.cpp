#include"global.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> min_left(nums.size(), 0);
        vector<int> max_right(nums.size(), 0);
        min_left[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            min_left[i] = min(min_left[i - 1], nums[i]);
        max_right[nums.size() - 1] = nums[nums.size() - 1];
        for (int j = nums.size() - 2; j >= 0; j--)
            max_right[j] = max(max_right[j + 1], nums[j]);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > min_left[i] && nums[i] < max_right[i])
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> a = {5,  1,6};
    Solution().increasingTriplet(a);
}