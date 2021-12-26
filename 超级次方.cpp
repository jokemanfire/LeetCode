#include"global.h"
class Solution {
public:
    int Mod = 1337;
    int superPow(int a, vector<int>& b) {
   
      
        return  dfs(a, b,b.size()-1);

    }
    int dfs(int a,vector<int> & b,int index)
    {
        if (index == -1)
            return 1;
        kpow(dfs(a, b, index - 1),10) + kpow(a, b[index]);
    }
    int kpow(int a, int b)
    {
        int sum = 1;
        while (b > 0)
        {
            sum = ((a % Mod) * (sum % Mod)) % Mod;
            b--;
        }
        return sum;
    }
};

int main()
{
    int a = 2147483647;
    vector<int> b = { 2,0,0 };
    Solution().superPow(a,b);
}