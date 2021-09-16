#include"global.h"


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> now;
        GetSum(candidates, now, target, result);
        return result;

    }
    void GetSum(vector<int>& Source, vector<int> Now, int target, vector<vector<int>> &result)
    {
        if (accumulate(Now.begin(), Now.end(), 0) == target)
        {
            sort(Now.begin(), Now.end());
            if(!Get_same(result,Now))
            result.push_back(Now);
            return;
        }
        else if(accumulate(Now.begin(), Now.end(), 0) <target)
        {
            for (int i = 0; i < Source.size(); i++)
            {
                vector<int> NewNow = Now;
                NewNow.push_back(Source[i]);
                GetSum(Source, NewNow, target, result);
            }
        }
        else
        {
            return;
        }
    }
    bool Get_same(vector<vector<int>>& result, vector<int>& Now)
    {
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == Now)
                return true;
        }
        return false;
    }
    
};

int main()
{
    Solution s;
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;
    vector<vector<int>> result;
    result = s.combinationSum(candidates,target);
    getchar();
}