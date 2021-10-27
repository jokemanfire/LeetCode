#include"global.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > AllData(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
            AllData[0][j] = 1;
        for (int i = 0; i < m; i++)
            AllData[i][0] = 1;
        for(int i=1;i<m;i++)
            for (int j = 1; j < n; j++)
            {
                AllData[i][j] = AllData[i - 1][j] + AllData[i][j - 1];
            }
        return AllData[m-1][n-1];
    }
};

int main()
{
   int result =  Solution().uniquePaths(3, 7);
   return 1;
}