#include"global.h"
class Solution {
public:
    vector<int> InitNums;
    Solution(vector<int>& nums) {
        InitNums = nums;
    }

    vector<int> reset() {
        return InitNums;
    }

    vector<int> shuffle() {
        vector<int>Randoms(InitNums.size(), 1);
        vector<int>shufflter = InitNums;
        for (int i = shufflter.size()-1; i > -1; i--)
        {
            int index = rand() % Randoms.size();
            int choss = Randoms[index];
            while (choss == 0)
            {
                index = rand() % Randoms.size();
                choss = Randoms[index];

            }
            Randoms[index]--;
            
            int temp = shufflter[i];
            shufflter[i] = shufflter[index];
            shufflter[index] = temp;

        }
        return shufflter;
    }
};

int main()
{
    vector<int> Data = { 1,2,3 };
    Solution a = Solution(Data);
    a.shuffle();
    a.reset();
}