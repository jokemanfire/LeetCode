#include"global.h"


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        int minrow = ops[0][0];
        int mincol = ops[0][1];
        for (int i = 0; i < ops.size(); i++)
        {
            int row = ops[i][0];
            int col = ops[i][1];
            if (row < minrow)
                minrow = row;
            if (col < mincol)
                mincol = col;
        }
        return minrow * mincol;
    }
};


int main()
{
    vector<vector<int>> temp = {};
    int a = 4000;
    int b = 4000;
    Solution().maxCount(a,b,temp);
}