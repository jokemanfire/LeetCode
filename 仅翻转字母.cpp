#include"global.h"

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int first = 0;
        int last = s.size() - 1;
        while (first < last)
        {
            while (first<last &&!JudgeEng(s[first]))
            {
                first++;
            }
            while (last> first!JudgeEng(s[last]))
            {
                last--;
            }
            if (first < last)
            {
                char temp = s[first];
                s[first++] = s[last];
                s[last--] = temp;
            }
        }
        return s;
    }
    bool JudgeEng(char a)
    {
        if (a >= 'a' && a <= 'z')
            return true;
        else if (a >= 'A' && a <= 'Z')
            return true;
        return false;
    }
};
int main()
{
    string s = "ab-cd";
    Solution().reverseOnlyLetters(s);
}