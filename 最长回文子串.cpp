#include"global.h"
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> Result(s.size(), vector<bool>(s.size(), 0));
        string R;
        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (j - i <= 1)
                {
                    Result[i][j] = s[i] == s[j] ? true : false;
                }
                else
                {
                    Result[i][j] = Result[i + 1][j - 1] & (s[i] == s[j]);
                }
                if (Result[i][j] == true && j - i >= R.size())
                    R = s.substr(i,j-i==0?1:j-i);
            }
        }
        return R;
    }
};

int main()
{
    string data = "tmikrmvnkzwffmuycgffiqnrepltnfvnggtmwkzmpjpcfuhmdcdlrupmqbimvppbnqinwcuidfckveonfgcknihwztkvrikfunegxfboluzjhxkoxdvdxoczqdkyjziqmjnnrbvcolyxijemlujjofuojdwfhcgzmmnsznhbv";
    Solution().longestPalindrome(data);
}