#include"global.h"

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> result;
//        vector<int> one_result;
//        int max_time = 0;
//        for (int i = n; i > n - k; i--)
//            max_time += i;
//        for (int i = 1; i <= max_time; i++)
//        {
//            Get_oneSum(result, i, one_result,k,n);
//        }   
//        for (int i = 0; i < result.size(); i++)
//        {
//            for (int j = 0; j < result[i].size(); j++)
//            {
//                cout << " " << result[i][j];
//            }
//            cout << endl;
//        }
//        return result;
//    }
//    void Get_oneSum(vector<vector<int>>& result, int res,vector<int> one_result,int k,int n)
//    {
//        if (one_result.size() > k || res < 0)
//            return;
//        if (res == 0 && one_result.size() == k)
//        {
//            sort(one_result.begin(), one_result.end());
//            if(find(result.begin(),result.end(),one_result)== result.end())
//            result.push_back(one_result);
//            return;
//        }
//      
//        for (int i = n; i >= 1; i--)
//        {
//            vector<int> temp =  one_result;
//            if (find(temp.begin(), temp.end(), i) != temp.end())
//                continue;
//            temp.push_back(i);
//            Get_oneSum(result, res-i, temp, k,n);
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
    vector<vector<vector<int>>> result(k+1) ;
    vector<int> temp;
    for (int i = 1; i <= n; i++)
    {
        temp.clear();
        temp.push_back(i);
        result[0].push_back(temp);
        result[1].push_back(temp);
    }

    vector<int> one_result;
    for (int i = 2; i <= k; i++)  //总共为K组 
    {
       
        for (int j = 0; j < result[i - 1].size() ; j++) //为前一组的迭代
        {
            
            for (int k = 0; k < result[0].size(); k++)  //对第0组迭代
            {
                one_result.clear();
                one_result = result[i - 1][j];   //前一组的第几个数组
                if (one_result[one_result.size() - 1] >= n) //最后一个值大于最大值
                {
                    break;
                }
                if (one_result[one_result.size() - 1] < result[0][k][0])
                {
                    one_result.push_back(result[0][k][0]);
                    result[i].push_back(one_result);
                }
                else
                    continue;
               
            }
        }
        

    }

    return result[k];
    }
};

int main()
{
    Solution s;
    s.combine(20, 7);
}