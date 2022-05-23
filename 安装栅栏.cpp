#include"global.h"
class Solution {
public:
	bool IsotherSide(vector<vector<int>>& trees, vector<int>& Tree_s, vector<int>& Tree_d)
	{
		int count_d = 0;
		int count_f = 0;
		if (Tree_s[0] - Tree_d[0] == 0)
		{

			for (int i = 0; i < trees.size(); i++)
			{
				vector<int> Tree_temp = trees[i];
				if (Tree_temp[0] <= Tree_s[0])
					count_d++;
				if (Tree_temp[0] >= Tree_s[0])
					count_f++;
			}

		}
		else
		{
			float k = (Tree_s[1] - Tree_d[1]) / float(Tree_s[0] - Tree_d[0]);
			float b = Tree_d[1] - (float)Tree_d[0] * k;
			for (int i = 0; i < trees.size(); i++)
			{
				vector<int> Tree_temp = trees[i];
				if (Tree_temp[1] <= Tree_temp[0] * k + b)
					count_d++;
				if (Tree_temp[1] >= Tree_temp[0] * k + b)
					count_f++;
			}
		}

		if (count_f == trees.size() || count_d == trees.size())
			return true;
		else
			return false;
	}
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		set<vector<int> >Result;
		//找到都在同一侧的围栏
		for (int i = 0; i < trees.size(); i++)
		{
			vector<int> Tree_d = trees[i];
			for (int j = i; j < trees.size(); j++)
			{
				vector<int> Tree_s = trees[j];
				if (Tree_d != Tree_s)
				{
					/*vector<int> k = { 11,10 };
					vector<int> k2 = {7,13};
					if (Tree_d == k && Tree_s == k2)
						cout << endl;*/
					//判断是否在同一侧
					if (IsotherSide(trees, Tree_s, Tree_d))
					{
						
						Result.insert(Tree_d);
						Result.insert(Tree_s);
					}
				}
			}
		}
		vector<vector<int>> v_result;
		for (auto i = Result.begin(); i != Result.end(); i++)
		{
			v_result.push_back(*i);
		}
		return v_result;
	}
};

int main()
{
	vector<vector<int>> Trees = { 1,5 };
	Solution().outerTrees(Trees);
}