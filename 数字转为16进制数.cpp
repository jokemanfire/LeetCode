#include"global.h"

class Solution {
public:
    string toHex(int num) {
        string result;
        unsigned temp = num;
        printf("%x", num);
        while (temp != 0)
        {
            char a = temp & 0xf;
            if (a >= 10)
            {
                a = 'a' + a - 10;
            }
            result.insert(result.begin(), a);
            temp >>= 4;
        }
        return result;
    }
};

int main()
{
    int a = 24;
    Solution().toHex(a);
}