#include"global.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                mask[i] |= (1<< words[i][j] - 'a');
            }
        }
        int Max_len = 0;
        for (int i = 0; i < mask.size(); i++)
        {
            for (int j = mask.size() - 1; j > i; j--)
            {
                if ( (mask[i] & mask[j]) == 0 && words[i].size() * words[j].size() > Max_len)
                    Max_len = words[i].size() * words[j].size();
            }
        }
        return Max_len;
    }
};

int main()
{
    vector<string> words = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
    Solution().maxProduct(words);
}