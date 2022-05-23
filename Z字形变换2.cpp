#include "global.h"

class Solution {
public:
	string convert(string s, int numRows) {
		int midrows = numRows - 2;
		int Copse = midrows + numRows;
		string Result;
		for (int i = 0; i < numRows; i++)
		{
			int count = 0;
			while (i + count * Copse < s.size())
			{

				Result.push_back(s[i + count * Copse]);
				int index2 = i + (count + 1) * (Copse - i * 2);
				if (i != 0 && i != numRows-1)
				{
					if (index2 < s.size())
						Result.push_back(s[index2]);
				}
				count++;
			}

		}
		return Result;
	}
};

int main()
{
	string data = "PAYPALISHIRING";
	int nums = 3;
	Solution().convert(data,nums);
}