#include"global.h"

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> Texts;
        vector<string> Result;
        int i = 0;
        string temp;
        while (i < text.size())
        {
            if (text[i] != ' ' )
            {
                temp += text[i];
                if(i == text.size()-1)
                    Texts.push_back(temp);
            }
            else
            {
                Texts.push_back(temp);
                temp = "";
            }
            i++;
        }
        for (int i = 0; i < Texts.size() - 2; i++)
        {
            if (Texts[i] == first && Texts[i + 1] == second)
            {
                Result.push_back(Texts[i + 2]);
            }
        }
        return Result;

    }

};

int main()
{
    string s = "alice is a good girl she is a good student";
    string r = "a";
    string c = "good";
    Solution().findOcurrences(s,r,c);
}