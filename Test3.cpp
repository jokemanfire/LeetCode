#include"global.h"

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>Customer;
	for (int i = 0; i < n; i++)
	{
		vector<int> CinData(2, 0);
		cin >> CinData[0] >> CinData[1];
		Customer.push_back(CinData);
	}
	int Max_choose = 0;
	//穷举法
	for (int i = 5; i < pow(2,n); i++)
	{
		int temp = i;
		vector<bool>choosed_data(m+1, true);
		int Temp_max = 0;
		int MCount = 0;
		while (temp != 0)
		{
		
			int choose = temp & 1;
			if (choose == 1)//取该guke
			{
				if (choosed_data[Customer[MCount][0]] && choosed_data[Customer[MCount][1]])
				{
					choosed_data[Customer[MCount][0]] = false;
					choosed_data[Customer[MCount][1]] = false;
					Temp_max++;
				}
			}
			MCount++;
			temp >>= 1;
		}
		if (Temp_max > Max_choose)
			Max_choose = Temp_max;

	}

	return Max_choose;
}