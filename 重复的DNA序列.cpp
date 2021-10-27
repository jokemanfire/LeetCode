#include"global.h"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        map<string, int> hashMap;
        if (s.size() < 10)
            return result;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = s.substr(i, 10);
            auto it = hashMap.find(temp);
            if (it != hashMap.end() && it->second == 1)
            {
                result.push_back(temp);
                hashMap[temp] = hashMap[temp] + 1;
            }
            else if (it == hashMap.end())
                hashMap[temp] = 1;
            else
                hashMap[temp] ++;
        }
        return result;
    }
};

int main()
{
    string test = { "AAAAAAAAAAAAA" };
    Solution().findRepeatedDnaSequences(test);
}