#include "global.h"

int main()
{
	int counts;
	cin >> counts;
	getchar();
	vector<int> CinData;
	vector<vector<int>>Result;
	for (int i = 0; i < counts; i++)
	{
		int temp;
		cin >> temp;
		CinData.push_back(temp);
	}
	int count = 1;
	while (count <= CinData.size())
	{
		for (int i = 0; i < CinData.size(); i++)
		{
			int sum = 1;
			int temp = 0;
			vector<int> Predata;
			while (temp < count  && i+temp<CinData.size())
			{
				sum *= CinData[i + temp];
				Predata.push_back(CinData[i + temp]);
				temp++;
			}
			if (sum == 1 && temp == count)
				Result.push_back(Predata);

		}
		count++;
	}
	cout << Result.size() << endl;
	return 1;

}