#include"global.h"
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int p_end = arr.size() - 1;
        int p_start = 0;
        vector<int> Meld;
        while (p_end > 0)
        {
            //每次获取当前最大值
            int Max_data = p_end + 1;
            p_start = 0;
            while (arr[p_start] != Max_data)
            {
                p_start++;
            }
            //双指针交换 把最大值放到第一个
            int Swap_start = 0;
            int Swap_end = p_start;
            Meld.push_back(Swap_end+1);
            while (Swap_end > Swap_start)
            {
                int temp = arr[Swap_end];
                arr[Swap_end] = arr[Swap_start];
                arr[Swap_start] = temp;
                Swap_end--;
                Swap_start++;
            }
            Meld.push_back(p_end+1);
            //直接倒序前面
            reverse(arr.begin(),arr.end()-(arr.size()-p_end-1));
            p_end--;
        }
        return Meld;

    }

};

int main()
{
    vector<int> temp = { 3,2,4,1 };
    Solution().pancakeSort(temp);
}