#include"global.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count=0;
        sort(ages.begin(), ages.end());
        for (int i = 0; i < ages.size(); i++)
        {
            for(int j= ages.size()-1;j>i;j--)
                if (ISend(ages[j], ages[i]))
                {
                    count++;
                    if (ages[j] == ages[i])
                        count++;
                }
        
        }



        return count;
    }
    bool ISend(float x,float y)
    {
        if (x >= y && x * 0.5 + 7 < y && (x >= 100 || y <= 100))
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> data;
    for (int i = 0; i < pow(10, 4); i++)
    {
        data.push_back(rand() % 120 + 1);
    }

    Solution().numFriendRequests(data);
}