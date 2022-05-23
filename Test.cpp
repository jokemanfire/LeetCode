#include"global.h"


bool isDouble(int data)
{
	int count = 0;
	while (data != 0)
	{
		if (data % 10 == 1)
			count++;
		data /= 10;
	}
	if (count >= 2)
		return true;
	return false;
}
int main()
{
	int counts;
	cin >> counts;
	getchar();
	for (int i = 0; i < counts; i++)
	{
		int temp;
		cin >> temp;
		if (temp % 11 == 0 || isDouble(temp))
		{
			cout << "yes"<<endl;
		}
		else
			cout << "no"<<endl;
	}
	
}