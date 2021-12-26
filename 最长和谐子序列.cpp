#include"global.h"
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> re;
        for (int i = 0; i < nums.size(); i++)
        {
            re[nums[i]]++;
        }
        int maxz = 0;

        for (auto it = re.begin(); it != re.end(); it++)
        {
            if (re.find(it->first + 1) != re.end())
            {
                if (it->second + re[it->first + 1] > maxz)
                    maxz = it->second + re[it->first + 1];
            }
        }
        return maxz;
    }
};

int main()
{
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    Solution().findLHS(nums);
}