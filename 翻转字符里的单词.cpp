#include "global.h"

class Solution {
public:
    string reverseWords(string s) {
        regex ws_re("(\\S+)");
        string data;

        vector<string> v;
        for (sregex_token_iterator it(s.begin(), s.end(), ws_re); it != sregex_token_iterator(); it++)
        {
            cout << *it << endl;
            v.push_back(*it);
        }

 
        for (auto i : v)
            cout << i;
        reverse(v.begin(), v.end());
        for (auto i : v)
        {
            data += i;
            if(i != *(v.end()-1))
            data += " ";
            
        }
        return data;
    }
};

int main()
{
    string s = " hello world  ";
    Solution().reverseWords(s);
}