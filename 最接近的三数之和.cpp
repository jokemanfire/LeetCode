#include"global.h"



bool return_bigger(int a, int b)
{
    return a > b ;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
   
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++)
        {
            int temp1 = nums[i];
            int res = target - temp1;

            int max_point = nums.size() - 1;
            int min_point = i+1;
            while (min_point < max_point)
            {
                if (abs( target - nums[min_point] - nums[max_point] - temp1) < abs(target - result))
                {
                    result = nums[min_point] + nums[max_point] + temp1;
                    printf("number : %d, %d, %d", nums[min_point], nums[max_point], temp1);
            
                }
                if (nums[min_point] + nums[max_point] < res)
                    min_point++;
                else if (nums[min_point] + nums[max_point] > res)
                    max_point--;
                else
                {
                    return target;
                }
            }
        }
        return result;
    }
};


int main()
{
    vector<int> nums = { -1,2,1,-4 };
    int target = 1;
    Solution().threeSumClosest(nums,target);
}