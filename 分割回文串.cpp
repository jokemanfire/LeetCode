#include"global.h"
class Solution {
public:
	vector<vector<string>> Result;
	vector<string>tempstring;
	bool hui(string& data)
	{
		int i = 0;
		int j = data.size() - 1;
		while (i != j && i<data.size()&&j>=0)
		{
			if (data[i++] != data[j--])
				return false;
		}
		return true;
	}

	void ISverser(string s)
	{
		if (s.size() == 0)
		{
			Result.push_back(tempstring);
			return;
		}
		else
		{
			for (int i = 1; i <= s.size(); i++)
			{
			
				string temp = s.substr(0, i);
				if (hui(temp))
				{
					tempstring.push_back(temp);
					ISverser(s.substr(i, s.size()));
					tempstring.pop_back();
				}
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<string> Now_string;
		ISverser(s);
		return Result;
	}
};

int main()
{
	Solution().partition("aab");
}