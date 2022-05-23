#include "global.h"
class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		vector<int> Result;
		vector<int> Decrease_day(security.size(), 0);
		vector<int> Increase_day(security.size(), 0);
		for (int i = 1; i < security.size(); i++)
		{
			if (security[i] <= security[i - 1])
				Decrease_day[i] = Decrease_day[i - 1] + 1;
		}
		for (int j = security.size() - 2; j > -1; j--)
		{
			if (security[j] <= security[j + 1])
				Increase_day[j] = Increase_day[j + 1] + 1;
		}
		for (int i = 0; i < Decrease_day.size(); i++)
		{
			if (Decrease_day[i] >= time && Increase_day[i] >= time)
				Result.push_back(i);
		}
		return Result;
	}
};
int main()
{
	vector<int> Test = { 1,1,1,1};
	Solution().goodDaysToRobBank(Test,0);
}