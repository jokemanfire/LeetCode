#include"global.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int> Hashm;
        vector<int> result;
        for (int i = 0; i < p.size(); i++)
        {
            Hashm[p[i]]++;
        }
        int i = 0;
        int j = 0;
        unordered_map <char, int> temp;
        for (; i < s.size() && j< s.size(); )
        {
            if (j - i < p.size())
            {
                while (j - i < p.size() && j<s.size())
                {
                    temp[s[j++]]++;
                }
            }
            else
            {
                if ((temp[s[i]]) == 1)
                {
                    temp.erase(s[i++]);
                }
                else
                    temp[s[i++]]--;
                    
                temp[s[j++]]++;
            }
            if (temp == Hashm)
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    string s = "cbaebabacd", p = "abc";
    Solution().findAnagrams(s, p);
}