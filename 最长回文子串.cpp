#include"global.h"

class Solution {
public:
    string longestPalindrome(string s) {

        string reverse_data = s;
        reverse(reverse_data.begin(), reverse_data.end());
        vector<vector<int>> result(s.size()+1,vector<int> (s.size()+1,0));
        vector<vector<int>> flags(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < reverse_data.size(); j++)
            {
                if (s[i] == reverse_data[j])
                {
                    result[i + 1][j + 1] = result[i][j] + 1;
                    flags[i + 1][j + 1] = 1;
                }
                else
                    result[i + 1][j + 1] = max(result[i + 1][j], result[i][j + 1]);
            }
        }
        int maxr = result[s.size()][reverse_data.size()];
        string resultstring;
        for(int i=1;i<= flags.size()-maxr;i++)
            for (int j = 1; j <= flags[i].size()-maxr; j++)
            {
                resultstring.clear();
                int k = 1;
                if (flags[i][j] == 1)
                {
                    while (k <= maxr)
                    {
                        resultstring += s[i + k - 2];
                        if (i + k < flags.size() && j + k < flags.size() && flags[i + k][j + k] != 1)
                        {
                            break;
                        }
                        else
                            k++;
                    }
                    if (k >= maxr)
                        return resultstring;
                }
            }
        return resultstring;
    }
};

int main()
{
    string data = "aacabdkacaa";
    Solution().longestPalindrome(data);
}