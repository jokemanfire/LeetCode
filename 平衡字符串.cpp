#include"global.h"
class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> data;
  
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (data.size() != 0 &&data.top() == 'R' && s[i] == 'L')
            {
                data.pop();
             
            }
            else if (data.size() != 0 && data.top() == 'L' && s[i] == 'R')
            {
                data.pop();
            }
            else
            {
                data.push(s[i]);
            }
            if (data.size() == 0)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    string data = "RLRRRLLRLL";
    int res = s.balancedStringSplit(data);
    getchar();

}