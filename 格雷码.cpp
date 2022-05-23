#include"global.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>befor_gry = { 0,1 };
        if (n == 1)
            return befor_gry;
        for (int i = 2; i <= n; i++)
        {
            vector<int> now_gray_data = befor_gry;
            reverse(befor_gry.begin(), befor_gry.end());
            now_gray_data.insert(now_gray_data.end(), befor_gry.begin(), befor_gry.end());
            int end = now_gray_data.size() / 2;
            for (int k = end; k < now_gray_data.size(); k++)
            {
                int prefx = pow(2, i-1);
                now_gray_data[k] |= prefx;
            }
            befor_gry = now_gray_data;
        }
        return befor_gry;
    }
};

int main()
{
    Solution().grayCode(4);
}