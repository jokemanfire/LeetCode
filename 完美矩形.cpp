#include"global.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int totalCover = 0;
        map<pair<int, int>, int> m1;

        for (auto& it : rectangles) {
            totalCover += (it[2] - it[0]) * (it[3] - it[1]);
            m1[{it[0], it[1]}]++;
            m1[{it[2], it[3]}]++;
            m1[{it[0], it[3]}]++;
            m1[{it[2], it[1]}]++;
        }

        vector<pair<int, int>> res;
        for (auto& it : m1) {
            if (it.second % 2 == 1) {
                res.emplace_back(it.first);
            }
        }

        if (res.size() != 4) return false;
        sort(res.begin(), res.end());
        int resA = (res[3].first - res[0].first) * (res[3].second - res[0].second);

        return resA == totalCover ? true : false;
    }
};

int main()
{
    vector< vector<int>> Square = { {0,0,1,1},{0,0,2,1},{1,0,2,1},{0,2,2,3} };
    Solution().isRectangleCover(Square);
}