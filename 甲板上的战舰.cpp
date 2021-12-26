#include"global.h"

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        vector<vector<bool>> Flags(board.size(), vector<bool>(board[0].size(), false));
        int sums = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (Flags[i][j] == false && board[i][j] == 'X')
                {
                    DeepOne(Flags, board, i, j);
                    sums += 1;
                }
            }
        }
        return sums;
    }
    void DeepOne(vector<vector<bool>>& Flags, vector<vector<char>>& board, int x, int y)
    {
        Flags[x][y] = true;
        if (x - 1 >= 0 && board[x-1][y] == 'X' && Flags[x-1][y] == false)
        {
            DeepOne(Flags, board, x - 1, y);
        }
        if (x + 1 < board.size() && board[x + 1][y] == 'X' && Flags[x + 1][y] == false)
        {
            DeepOne(Flags, board, x + 1, y);
        }
        if (y - 1 >= 0 && board[x ][y-1] == 'X' && Flags[x][y-1] == false)
        {
            DeepOne(Flags, board, x, y - 1);
        }
        if (y + 1 < board[0].size() && board[x][y+1] == 'X' && Flags[x][y+1] == false)
        {
            DeepOne(Flags, board, x, y + 1);
        }
        return;

    }
};

int main()
{
    vector<vector<char>>  board = { {'X','.','.','.'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution().countBattleships(board);
}