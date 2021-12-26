#include"global.h"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1 = { 'q','w','e','r','t','y','u','i','o','p'};
        set<char> s2 = { 'a','s','d','f','g','h','j','k','l' };
        set<char> s3 = {'z','x','c','v','b','n','m'};
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (s1.find(tolower(words[i][j])) != s1.end())
                    count1++;
                if (s2.find(tolower(words[i][j])) != s2.end())
                    count2++;
                if (s3.find(tolower(words[i][j])) != s3.end())
                    count3++;
            }
            if (count1 == words[i].size() || count2 == words[i].size() || count3 == words[i].size())
                result.push_back(words[i]);
        }
        return result;
    }
};

int main()
{
    vector<string> data = { "Hello","Alaska","Dad","Peace" };
    Solution().findWords(data);
}