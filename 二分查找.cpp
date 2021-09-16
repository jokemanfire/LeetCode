#include"global.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find_index(0, nums.size() - 1, nums, target);

    }
    int find_index(int min, int max, vector<int>& nums, int target)
    {

        int index = (min + max) / 2;
        if (min > max)
            return -1;
        if (nums[index] == target)
            return index;
        else
        {
            if (nums[index] > target)
            {
                max = index - 1;
            }
            else if (nums[index] < target)
            {
                min = index + 1;
            }
            return find_index(min, max, nums, target);
        }
    }
};

int main()
{
    vector<int> data = { -1,0,3,5,9,12 };
    Solution s;
    s.search(data, 9);

}