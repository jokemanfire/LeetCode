#include"global.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<vector<int>> Allball(grid.size()+1, vector<int>(grid[0].size(),0));
        for (int i = 0; i < grid[0].size(); i++)
            Allball[0][i] = i;
        //对挡板数组迭代
        for (int i = 0; i < grid.size(); i++)
        {

            for (int j = 0; j < grid[i].size(); j++)
            {
                if (Allball[i][j] == -1)
                {
                    Allball[i + 1][j] = -1;
                    continue;
                }
                int col = Allball[i][j];
                if (col == 0)
                {
                    if (col + 1 < grid[i].size() && grid[i][col + 1] == 1 && grid[i][col] == 1)
                        Allball[i + 1][j] = Allball[i][j] + 1;
                    else
                        Allball[i + 1][j] = -1;
                }
                else if (col == grid[i].size() - 1)
                {
                    if (col - 1 > -1 && grid[i][col] == -1 && grid[i][col - 1] == -1)
                        Allball[i + 1][j] = Allball[i][j] - 1;
                    else
                        Allball[i + 1][j] = -1;
                }
                else if (col > 0 && col < grid[i].size() - 1)
                {
                    if (grid[i][col - 1] == 1 && grid[i][col] == -1)
                        Allball[i + 1][j] = -1;
                    else if (grid[i][col] == 1 && grid[i][col + 1] == -1)
                        Allball[i + 1][j] = -1;
                    else
                        Allball[i + 1][j] = Allball[i][j] + grid[i][col];
                }
            }
        }
        return Allball[grid.size()];
    }
};


int main()
{
    vector<vector<int>> grid = { {1, -1, -1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, -1, -1, -1, -1, 1},{-1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, 1},{1, -1, -1, -1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1} };
    Solution().findBall(grid);
}