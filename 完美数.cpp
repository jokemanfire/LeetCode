#include"global.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> Result;
        if (num == 1)
            return false;
        for (int i = 1; i <= sqrt(num); i++)
        {
            if ( num % i == 0)
            {
                Result.push_back(i);
                if(num/i != num)
                Result.push_back(num / i);
            }
        }
        if (accumulate(Result.begin(), Result.end(), 0) == num)
            return true;
        return false;
    }
};

int main()
{
    Solution().checkPerfectNumber(28);
}