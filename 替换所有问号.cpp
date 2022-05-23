#include"global.h"

class Solution {
public:
    string modifyString(string s) {
        if (s.size() == 1)
            return "a";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[i + 1] != '?')
                        s[i] = (s[i + 1] + 1 - 'a') % 26 + 'a';
                    else
                        s[i] = 'a';
                }
                else if (i == s.size() - 1)
                {
                    s[i] = (s[i - 1] + 1 - 'a') % 26 + 'a';
                }
                else if (i > 0 && i < s.size() - 1)
                {
                    char a = (s[i - 1] + 1 - 'a') % 26 + 'a';
                    if (a == s[i + 1])
                        s[i] = (a + 1 - 'a') % 26 + 'a';
                    else
                        s[i] = a;
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution().modifyString("ubv?w");
}