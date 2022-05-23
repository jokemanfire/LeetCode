#include"global.h"

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int max_index =1;
        int second_index =0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[max_index])
            {
                second_index = max_index;
                max_index = i;
            }
            else if (nums[i] > nums[second_index] && i!= max_index)
            {
                second_index = i;
            }
        }
        
        return max_index >= second_index * 2 ? max_index: -1;
    }
};
int main()
{
    vector<int> a = { 1,2,3,4};
    Solution().dominantIndex(a);
}