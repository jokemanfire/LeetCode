#include"global.h"

class Solution {
public:
	vector<string> Result;
	void GetOne(string s, int count, string This_data)
	{

		if (s.size() == 0 || count < 0)
		{
			if (s.size() == 0 && count == -1)
			{
				This_data.pop_back();
				Result.push_back(This_data);
			}
			return;
		}
		else
		{
			for (int i = 1; i <= 3; i++)
			{
				if (s.size() < i)
					break;
				string str = s.substr(0, i);
				if (i >= 2 && s[0] == '0')
					break;
				int A_number = atoi(str.c_str());
				if (A_number >= 0 && A_number <= 255)
				{
					string temp = This_data;
					temp += str;
					temp += '.';
					GetOne(s.substr(i, s.size()), count-1, temp);
				}

			}

		}
	}

	vector<string> restoreIpAddresses(string s) {
		string This_data;
		GetOne(s, 3, This_data);
		return Result;
	}
};
int main()
{
	Solution().restoreIpAddresses("101023");
}