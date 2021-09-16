#include"global.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int max_height = height[i];
            int max_index = height.size()-1;
            int One_cyclemax = 0;
            for (int j = max_index; j > i; j--)
            {
                if (max_height * (j - i) < One_cyclemax)
                    break;
                else if (height[j] >= max_height)
                {
                    One_cyclemax = max_height * (j - i);
                    break;
                }
                else
                {
                    int temp = min(height[j],max_height) * (j - i);
                    if (temp > One_cyclemax)
                        One_cyclemax = temp;
                }
            }
            if (One_cyclemax > max)
                max = One_cyclemax;

        }
        return max;

    }
};

int main()
{
    vector<int> test = { 1,2,1 };
    Solution().maxArea(test);
}