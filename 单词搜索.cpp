#include"global.h"

class Solution {
public:
	bool IsCorrect(vector<vector<char>>& board, int row, int col, string& word, int index, vector<vector<bool>> Vistied)
	{
		if (row < 0 || row >= board.size())
			return false;
		if (col <0 || col >=board[0].size())
			return false;
		if (index > word.size() - 1 || Vistied[row][col] == true)
			return false;
		else
		{
			if (word[index] == board[row][col] && index == word.size() - 1)
				return true;
		}
		if (word[index] != board[row][col])
			return false;
		else
		{
			Vistied[row][col] = true;
			bool left_flag = IsCorrect(board, row, col - 1, word, index + 1, Vistied);
			bool right_flag = IsCorrect(board, row, col + 1, word, index + 1, Vistied);
			bool up_flag = IsCorrect(board, row - 1, col, word, index + 1, Vistied);
			bool down_flag = IsCorrect(board, row + 1, col, word, index + 1, Vistied);
			return left_flag | right_flag | up_flag | down_flag;
		}

	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> Vistied;
		Vistied.resize(board.size());
		for (int i = 0; i < board.size(); i++)
			Vistied[i].resize(board[i].size());

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				vector<vector<bool>> temp = Vistied;
				if (IsCorrect(board, i, j, word, 0, temp))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<char>> board = { {'A','B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
	string word = "ABCB";
	Solution().exist(board, word);
}