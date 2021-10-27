#include"global.h"
#include<map>
#include<vector>
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> hashmap = { {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"} };
        string result;
        vector<int> Allmap = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
        while (num != 0)
        {
            for (int i = Allmap.size() - 1;i>-1; i--)
            {
                if (num >= Allmap[i] && num<= Allmap[i] *4-1)
                {
                    int times = num / Allmap[i];
                    num -= Allmap[i] * times;
                    for(int j=0;j< times;j++)
                    result += hashmap[Allmap[i]] ;
                    break;
                }
            }
            
        
        }
        return result;
    }
};

int main()
{
    int a = 3999;
    Solution().intToRoman(a);
}