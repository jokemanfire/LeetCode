#include"global.h"


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res (2*n,"0");
        for (int i = 0; i < n; i++)
        {
            res.push_back("(");
            res.push_back(")");
        }
        Gendata(res);

    }
    void Gendata(vector<string> res)
    {
        for (int i = 0; i < res.size(); i++)
        {

        }
    }

};

int main()
{

}