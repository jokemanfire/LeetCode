#include"global.h"

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> dp;
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (dp.find(arr[i] - difference) != dp.end())
                dp[arr[i]] = 1 + dp[arr[i] - difference];
            else
                dp[arr[i]] = 1;
            if (dp[arr[i]] > max)
                max = dp[arr[i]];
        }
        return max;
        
    }
};


int main()
{
    vector<int> arr = { 1, 5, 7, 8, 5, 3, 4, 2, 1 };
    int difference = -2;
    Solution().longestSubsequence(arr,difference);
}