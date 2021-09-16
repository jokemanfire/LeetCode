#include<vector>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;


class Cout
{
private:
	vector<int>& data;
public:
	Cout(vector<int>& a) :data(a){
		sum = 0;
		for (int i = 0; i < data.size(); i++)
		{
			sum += data[i];
		}
	
	};
	int  pickup();
private:

	int sum;
	
};
int main()
{
	vector<int> b = { 8,3,4,5 };
	Cout t(b);
	for(int i =0;i<10;i++)
	{
		cout<<t.pickup()<<endl;
		
	}
	

	
}

int Cout::pickup()
{
	
	for (int i = 0; i < data.size(); i++)
	{
		int temp = rand() % sum;
		if (temp <= data[i])
			return i;
	}
}