#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


void return_result(string src, map<char, string> phoneMap, vector<string>& res, string one)
{
    if (src.size() != 0)
    {
        char tt = src[src.size() - 1];
        src.pop_back();
        string ttstring = phoneMap[tt];
        for (auto c : ttstring)
        {
            return_result(src, phoneMap, res, one+c);
        }

    }
    else
    {
        if(one.size()!=0)
        res.push_back(one);
    }

}

int main()
{
    string question = "23";
    map<char, string> phoneMap = {
         {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    reverse(question.begin(), question.end());
    vector<string> res;
    return_result(question, phoneMap, res, "");
    getchar();

}
