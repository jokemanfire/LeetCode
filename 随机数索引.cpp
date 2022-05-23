#include"global.h"
class Solution {
public:
    map<int, vector<int>>Indes;
    vector<int> bums;
    Solution(vector<int>& nums) {
        bums = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            Indes[nums[i]].push_back(i);
        }

    }

    int pick(int target) {
        int index = rand() % Indes[target].size();
        return Indes[target][index];
    }
};

int main()
{
    vector<int> nums = { 1,2,3,3,3 };
    Solution * obj = new Solution(nums);
    obj->pick(1);

}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */