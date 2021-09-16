#include"global.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int result = -1;
        ThirdFind(0, nums.size() - 1, nums, result);
        if (result == -1)
            return (* (nums.begin()) > *(nums.end()-1)) ? 0 : nums.size() - 1;
        return result;
    }
    int ThirdFind(int min, int max, vector<int>& nums, int& result)
    {
        if (result != -1)
            return -1;
        if (min == max)
        {
            return min;
        }
        int n1 = ThirdFind(min, (max + min) / 2, nums, result);
        int n2 = ThirdFind((max + min) / 2 + 1, max, nums, result);
        if (n1 != -1 && n2 != -1 && result == -1)
        {
            if (nums[n1] > nums[n2])
            {
                if (n1 - 1 >= 0 && nums[n1] > nums[n1 - 1])
                    result = n1;
                return (n1 - nums.size() / 2 < n2 - nums.size() / 2) ? n1 : n2;
            }
            if (nums[n1] < nums[n2])
            {
                if (n2 + 1 <= nums.size() - 1 && nums[n2] > nums[n2 + 1])
                    result = n2;
                return (n1 - nums.size() / 2 < n2 - nums.size() / 2) ? n1 : n2;
            }
        }
  
        return (n1 != -1) ? n1 : n2;
      

    }
};

int main()
{
    vector<int> nums = { 1,2,5,4,3,2,1};
    Solution s;
    s.findPeakElement(nums);

}