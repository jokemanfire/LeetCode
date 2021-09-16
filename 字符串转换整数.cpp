#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
    string s = "4193 with words";
    bool flag = false; //知道遇到第一个符号 或者数字都为false
    bool data_flag = true;//默认为正值
    long long int result = 0;
    int index = -1;
    for (int i = 0; i < s.size() && flag == false; i++)
    {
        //如果有空格 丢弃
        if (s[i] == ' ')
            flag = false;
        //如果有+ 或者 -号 读入符号
        else if (s[i] == '+' || s[i] == '-')
        {
            flag = true;
            data_flag = true;
            index = i + 1;
            if (s[i] == '-')
                data_flag = false;
        }
        //遇到第一个数字 flag置为true
        else if (s[i] >= '0' && s[i] <= '9')
        {
            flag = true;
            data_flag = true;
            index = i;
        }
        else
            break;
    }
    if (index == -1)
        return 0;

    for (int i = index; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (i != index)
        
             result *= 10;
             result += (s[i] - '0');
           
            if (result >= (long long int)INT_MAX + 1)
            {
                result = (long long int)INT_MAX + 1;
                break;
            }
        }
        else
            break;
    }
    if (data_flag == false)
    {
        result = -result;
    }
    else
    {
        if (result == (long long int)INT_MAX + 1)
            result--;
    }
    cout << result;
    getchar();
    return result;
}