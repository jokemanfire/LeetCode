#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int> res,vector<int> present,vector<vector <int>> &result)
{
	if (res.size() != 0)
	{
		vector<int> sotrage = res;
		for (int i = 0; i < res.size(); i++)
		{
			int temp = res[i];
			res.erase(res.begin() + i);
			vector<int> next = present;
			next.push_back(temp);
			permute(res, next, result);
			res = sotrage;
		}
	}
	else
	{
		result.push_back(present);
	}
}

int main()
{
	vector<int> nums = { 1,2,3 };
	vector<vector <int>> result;
	vector<int>start;
	permute(nums, start, result);

	getchar();
}