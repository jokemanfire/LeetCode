#include"global.h"


class Solution {
public:
    int findComplement(int num) {
        int b = 0;
        stack<int> result;
   
    
        int temp = 0;
        while (num != 0)
        {
            temp = num & 1;
            num >>= 1;
            result.push(temp);
        }
        while(!result.empty())
        {
            int a = result.top();
            result.pop();
            b <<= 1;
            b |= a == 1 ? 0:1;
  
        }

        return b;
    }
};

int main()
{
    Solution().findComplement(10);
}