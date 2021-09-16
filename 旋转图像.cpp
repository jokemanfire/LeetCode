#include"global.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    }
};

void move(vector<vector<int> >& matrix )
{
    int i, j, k;
    for (i = 0; i < matrix.size(); i++)
        for (j = 0; j < i; j++)
        {
            k = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = k;
        }
    for (i = 0; i < matrix.size(); i++)
        for (j = 0; j < matrix[i].size()/2; j++)
        {
            k = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[i].size()-1-j];
            matrix[i][matrix[i].size() - 1 - j] = k;
        }
}
int main()
{
    vector<vector<int> > data = { {1, 2, 3} ,{4, 5, 6},{7, 8, 9} };
    move(data);
    getchar();
}