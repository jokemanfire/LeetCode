#include"global.h"

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>Max_row;
        vector<int>Max_col;
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            Max_row.push_back(*max_element(grid[i].begin(), grid[i].end()));
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            int max_e = grid[0][i];
            for (int j = 0; j < grid.size(); j++)
                max_e = max(grid[j][i], max_e);
            Max_col.push_back(max_e);
        }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                result += (min(Max_row[i], Max_col[j]) - grid[i][j]);
            }

        return result;
    }
};
int main()
{
    vector<vector<int>> grid = { {3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0} };
    Solution().maxIncreaseKeepingSkyline(grid);
}