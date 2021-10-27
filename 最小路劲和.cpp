#include"global.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > result(grid.size(), vector<int>(grid[0].size(), 0));
        result[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
        {
            result[i][0] = result[i - 1][0] + grid[i][0];
       
        }
        for (int j = 1; j < grid[0].size(); j++)
        {
            result[0][j] = result[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < result.size(); i++)
        {
            for (int j = 1; j < result[0].size(); j++)
            {

                result[i][j] = min(result[i][j - 1] + grid[i][j], result[i - 1][j] + grid[i][j]);
            }
        }
        return result[result.size() - 1][result[0].size() - 1];
    }
};

int main()
{
    vector<vector<int>> grid = { {1,2,3},{4,5,6} };
    Solution().minPathSum(grid);
}