#include"global.h"



bool Cmp(vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
		vector<vector<int>> Result;
		sort(intervals.begin(), intervals.end(), Cmp);
		int i = 0;
		int n_min = intervals[0][0];
		int n_max = intervals[0][1];
		while(i < intervals.size()-1)
		{
			//如果有交集 继续
			if (n_max >= intervals[i + 1][0])
			{
				n_max = n_max > intervals[i + 1][1] ? n_max : intervals[i + 1][1];
				i += 1;
			}
			//如果没有交集 放入结果
			else
			{
				Result.push_back({ n_min, n_max });
				i++;
				n_min = intervals[i][0];
				n_max = intervals[i][1];
			}
		}
		Result.push_back({ n_min, n_max });
		return Result;
	}

};

int main()
{
	vector<vector<int>> data = { {1, 3},{2, 6},{8, 10},{15, 18} };
	Solution().merge((data));
}