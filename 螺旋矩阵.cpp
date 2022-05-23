#include"global.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int Max_left = 0;
		int Max_right = matrix[0].size()-1;
		int Max_down = matrix.size()-1;
		int Max_up = 0;
		int row = 0;
		int col = 0;
		vector<int>Result;
		while (Max_left <= Max_right || Max_up <= Max_down)
		{
			//向右
			while (col <= Max_right)
			{
				Result.push_back(matrix[row][col]);
				col++;
			}
			col--;
			Max_up++;
			//向下
			while (row <= Max_down)
			{
				Result.push_back(matrix[row][col]);
				row++;
			}
			row--;
			Max_right--;
			//向左
			while (col >= Max_left)
			{
				Result.push_back(matrix[row][col]);
				col--;
			}
			col++;
			Max_down--;
			//向上
			while (row >= Max_up)
			{
				Result.push_back(matrix[row][col]);
				row--;
			}
			row++;
			Max_left++;
		}

		return Result;
	}
};

int main()
{
	vector<vector<int>> a = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	Solution c;
	c.spiralOrder(a);
}