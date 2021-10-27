#include"global.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++)
        {
            bool b = findex(matrix[i], target, 0, matrix[i].size() - 1);
            if (b)
                return true;
        }
        return false;
    }

    bool findex(vector<int> data, int target, int min, int max)
    {
        int mid = (max + min) / 2;
        if (min > max)
            return false;
        else if (data[mid] == target)
            return true;
        else if (data[mid] < target)
            return findex(data, target, mid + 1, max);   
        else
            return findex(data, target, min, mid - 1);

    }
};

int main()
{
    vector<vector<int>>  matrix = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
       int target = 5;
    Solution().searchMatrix(matrix, target);

    
}