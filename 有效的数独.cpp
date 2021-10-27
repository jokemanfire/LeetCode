#include"global.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
            {

                if (!judge(board, i, j))
                    return false;
            }
        return true;
    }
    bool judge(vector<vector<char>>& board, int i, int j)
    {
        vector<int> flag(10, 0);

        //∫·œÚ≈–∂œ
        for (int clo = 0; clo < board[i].size(); clo++)
        {
            char data = board[i][clo];
            if (data == '.')
                continue;
            int index = data - '0';
            if (flag[index] == 0)
                flag[index] ++;
            else 
                return false;
        }
        flag.assign(10, 0);
        //◊›œÚ≈–∂œ
        for (int row = 0; row < board.size(); row++)
        {
            char data = board[row][j];
            if (data == '.')
                continue;
            int index = data - '0';
            if ( flag[index] == 0)
                flag[index] ++;
            else 
                return false;
        }
        flag.assign(10, 0);
        //∏Òƒ⁄≈–∂œ
        int blockrow = i % 3;
        int blockcol = j % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                char data = board[blockrow * 3 + i][blockcol * 3 + j];
                if (data == '.')
                    continue;
                int index = data - '0';
                if ( flag[index] == 0)
                    flag[index]++;
                else 
                    return false;
            }
        return true;
    }
};

int main()
{
    vector<vector<char>> test = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution().isValidSudoku(test);
}