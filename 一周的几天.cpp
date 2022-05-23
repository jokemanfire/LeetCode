#include"global.h"
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int startyear = 1971;
        vector<string> Dataday = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        vector<int> DaysF = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
        vector<int> DaysP = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
        int D_year = year - 1971;
        int counts = 0;
        //求年份
        for (int i = 0; i < D_year; i++)
        {
            if (((startyear + i) % 4 == 0 && (startyear+i)% 100 != 0)|| (startyear+i) % 400 == 0)
                counts += accumulate(DaysF.begin(), DaysF.end(), 0);
            else
                counts += accumulate(DaysP.begin(), DaysP.end(), 0);
        }

        //求月份
        int D_month = month - 1;
        bool year_type = (year % 4 == 0 && year%100 !=0) || year %400 ==0? true : false;
        if (year_type)
            counts += accumulate(DaysF.begin(), DaysF.begin() + D_month, 0);
        else
            counts += accumulate(DaysP.begin(), DaysP.begin() + D_month, 0);

        counts += (day - 1);
        return Dataday[(counts + 5) % 7];

    }
};
int main()
{
    Solution().dayOfTheWeek(3, 1, 2100);
}