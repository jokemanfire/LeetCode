#include"global.h"
#include<unordered_map>
class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		vector<bool> Servers(k, true);
		map<int, int> Tasks;
		vector<int> ServerCount(k, 0);
		for (int i = 0; i < arrival.size(); i++)
		{
			//将任务完成的Server置为true
			auto it = Tasks.begin();
			while (it != Tasks.end())
			{
				if (it->second!=-1&& it->second <= arrival[i])
				{
					Servers[it->first] = true;
					it->second = -1;
				}
				it++;
			}

			int Count_size = 0;
			int choose = (i + Count_size) % k;

			//选择server
			while (!Servers[choose] && Count_size < k)
			{
				Count_size++;
				choose = (i + Count_size) % k;
			}
			//说明有
			if (Count_size != k)
			{
				Servers[choose] = false;
				ServerCount[choose] ++;
				Tasks[choose] = load[i] + arrival[i];
			}
		}
		int max = *max_element(ServerCount.begin(), ServerCount.end());
		vector<int>result;
		for (int i = 0; i < ServerCount.size(); i++)
		{
			if (ServerCount[i] == max)
				result.push_back(i);
		}
		return result;
	}
};

int main()
{
	vector<int>arrival = { 1,2,3 };
	vector<int> load = { 1000000000,1,1000000000 };
	Solution().busiestServers(2,arrival,load);
}