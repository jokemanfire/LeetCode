#include"global.h"
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector < vector<int> > result(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < text1.size() + 1; i++)
            for (int j = 1; j < text2.size() + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    result[i][j] = result[i - 1][j - 1] + 1;
                }
                else
                {
                    result[i][j] = max(result[i][j - 1], result[i - 1][j]);
                }
            }
        return result[text1.size() ][text2.size()];
    }
};

int main()
{
    string text1 = "abced";
    string text2 = "def";
    int a = Solution().longestCommonSubsequence(text1, text2);
    return a;
}