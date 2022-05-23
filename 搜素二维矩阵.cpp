#include"global.h"

class Solution {
public:
	bool Binary_search(vector<int>& Ros, int& target, int min, int max)
	{
		if (min > max)
			return false;
		int mid = (min + max) / 2;
		if (Ros[mid] == target)
			return true;
		else if (Ros[mid] < target)
		{
			return Binary_search(Ros, target, mid + 1, max);
		}
		else
		{
			return Binary_search(Ros, target, min, mid - 1);
		}
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//先对行扫描
		int Rows = -1;
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			if (target >= matrix[i][0] && target < matrix[i + 1][0])
			{
				Rows = i;
				break;
			}
		}

		if (Rows == -1)
		{
			if (target >= matrix.back()[0] && target <= matrix.back().back())
				Rows = matrix.size() - 1;
			else
			{
				return false;
			}

		}
		//二分查找
		return Binary_search(matrix[Rows], target, 0, matrix[Rows].size() - 1);

	}
};

int main()
{
	vector<vector<int>> matrix = { {1},{3} };
	int target = 3;
	Solution().searchMatrix(matrix, target);
}