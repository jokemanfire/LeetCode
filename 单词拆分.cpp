#include"global.h"

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<vector<bool>> Istrue(s.size(), vector<bool>(s.size(), false));
		unordered_map<string, bool> Hashsmap;
		for (int i = 0; i < wordDict.size(); i++)
		{
			Hashsmap[wordDict[i]] = true;
		}
		//³õÊ¼»¯
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				string temp = s.substr(i, j - i + 1);
				if (Hashsmap[temp] == true)
					Istrue[i][j] = true;
			}
		}

		for (int i = s.size()-1; i >=0; i--)
		{
			for (int j = i; j <= s.size()-1; j++)
			{
				if(Istrue[i][j])
					continue;
				for (int k = i; k+1 <= j; k++)
				{
					Istrue[i][j] = Istrue[i][k] & Istrue[k+1][j];
					if (Istrue[i][j] == true)
						break;
				}
			}
		}
		return Istrue[0][s.size() - 1];
	}
};

int main()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
	Solution().wordBreak(s, wordDict);
}