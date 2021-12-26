#include"global.h"

class Solution {
public:
    int integerReplacement(int n) {
        
        int r;
        if (n == 1)
            return 0;
        else if (n % 2 == 0)
            r = integerReplacement(n / 2) + 1;    
        else
        {
            if (n == 2147483647)
                r = integerReplacement(n - 1);
            else
               r = min(integerReplacement(n + 1) + 1, integerReplacement(n - 1) + 1);

        }
        return r;

    }
};

int main()
{
    int r = Solution().integerReplacement(2147483647);
    cout << r;
}