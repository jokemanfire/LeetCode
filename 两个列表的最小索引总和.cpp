#include"global.h"

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		map<string, int> Room_bool;
		map<string, int> Room_int;
		for (int i = 0; i < list1.size(); i++)
		{
			Room_bool[list1[i]]++;
			Room_int[list1[i]] += i;
		}
		for (int i = 0; i < list2.size(); i++)
		{
			Room_bool[list2[i]]++;
			Room_int[list2[i]] += i;
		}
		vector<string>Result;
		int min_index = list1.size() + list2.size();
		for (int i = 0; i < list1.size(); i++)
		{
			if (Room_int[list1[i]] < min_index && Room_bool[list1[i]] == 2)
			{
				Result.clear();
				min_index = Room_int[list1[i]];
			}
			if (Room_bool[list1[i]] == 2 && Room_int[list1[i]]== min_index)
				Result.push_back(list1[i]);

		}
		
	
		
		return Result;
	}
};
int main()
{
	vector< string>a = { "Tapioca Express", "Burger King", "KFC","Shogun" };
	vector< string>b = { "Piatti", "The Grill at Torrey Pines", "KFC", "Shogun" };
	Solution().findRestaurant(a, b);
}