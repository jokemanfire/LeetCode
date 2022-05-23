#include"global.h"
#include<set>


int Min = 10000;
void GetEnegy(int Eng, int room, vector<int>& Boom, int index, int Rooms)
{
	if (index == Boom.size())
	{
		if (Eng < Min)
			Min = Eng;
		return;
	}

	if (Boom[index] == room)
	{
		for (int i = 1; i <= Rooms; i++)
		{
			GetEnegy(Eng + 1, i, Boom, index + 1, Rooms);

		}
	}
	else
		GetEnegy(Eng, room, Boom, index + 1, Rooms);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> Boom;
	int room = 1;
	int Custm = 0;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		Boom.push_back(temp);
	}
	GetEnegy(0, 1, Boom, 1, n);
	//for (int i = 1; i < Boom.size(); i++)
	//{
	//	if (Boom[i] == room)
	//	{
	//		//chang 到最远爆炸房间
	//		int New_s = (Boom[i] + 1) % (n + 1);
	//		set<int> sots;
	//		for (int j = i; j < Boom.size(); j++)
	//		{
	//			if (sots.size() < n )
	//				sots.insert(j);
	//		}
	//		for (int k = 1; k < n + 1; k++)
	//		{
	//			if (sots.find(k) == sots.end())
	//			{
	//				room = k;
	//				break;
	//			}
	//		}
	//		Custm++;
	//	}
	//}
	cout << Min;
}