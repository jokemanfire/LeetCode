#include"global.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> hash1;
        for (int i = 0; i < magazine.size(); i++)
        {
            hash1[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (hash1.count(ransomNote[i]) == 0 || hash1[ransomNote[i]] > 0)
            {
                return false;
            }
            else
                hash1[ransomNote[i]]--;
        }
        return true;
    }
};

int main()
{
    string a = "ab";
    string b = "aa";
    Solution().canConstruct(b,a);
}