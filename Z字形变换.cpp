#include"global.h"

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result;
        string all;
        if( numRows >=3 )
        for (int num = 0; num < numRows; num++)
        {
            string one_row;
            int midlen = numRows - 2;
            int count = s.size() % (midlen + numRows) == 0 ? 0 : 1;
            int rcol = s.size() / (midlen + numRows) +count;

            int step = midlen + numRows;
            if (num == 0 || num == numRows -1)
            for (int col = 0; col < rcol; col++)
            {
                if (num + step * col < s.size())
                one_row.push_back(s[num + step * col]);
            }
            else
            {
                for (int col = 0; col < rcol; col++)
                {
                    int index = num + step * col;
                    int index2 = num + step * (col + 1);
                    if (index < s.size())
                        one_row.push_back(s[index]);
                    if (index2 - 2 * num < s.size())
                        one_row.push_back(s[index2 - 2 * num]);
                }
            }
            result.push_back(one_row);
        }
        else if (numRows == 1)
            return s;
        else
        {
       
            int count = s.size() % 2 == 0 ? 0 : 1;
            int col = s.size() / 2 + count;
            for (int i = 0; i < numRows; i++)
            {
                string one_row;
                for (int j = 0; j < col; j++)
                {
                    int index = i + j * 2;
                    if (index < s.size())
                        one_row += s[index];
                }
                result.push_back(one_row);
            }
 
        }
      
        for (int i = 0; i < result.size(); i++)
            all += result[i];
        return all;
    }
};

int main()
{
    string s = "abc";
    int nums = 2;
    Solution().convert(s, nums);
    
}