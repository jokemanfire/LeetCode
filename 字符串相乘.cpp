#include"global.h"
class Solution {
public:
    string multiply(string num1, string num2) {

        int count = 0;//进位
        vector<string> mul_data;
        for (int i = num1.size()-1; i > -1; i--) //每一位做乘法
        {
            string One_mul;
            int temp1 = num1[i] - '0' ;
            count = 0;
            for (int j = num2.size()-1; j  > -1; j--)
            {
                int temp2 = num2[j] - '0';
                int multemp = temp1 * temp2 + count;
                char now_d = (multemp % 10 )+ '0';
                count = multemp / 10;
                One_mul += now_d;
            }
            if (count != 0)
                One_mul += (count + '0');
            reverse(One_mul.begin(), One_mul.end());
            string zero;
            for (int k = num1.size() - 1; k > i; k--)
            {
                zero += '0';
            }
            mul_data.push_back(One_mul +zero);
        }
        string sum;
        count = 0;
        //做加法
        for (int i = 0; i < mul_data.size(); i++)
        {
            int size1 = mul_data[i].size() - 1;
            int size2 = sum.size() - 1;
      
            string temp_sum;
            while (count != 0 || size1 > -1 || size2 >-1)
            {
                int temp1 = 0;
                int temp2 = 0;
                int one_sum;
                if(size1 > -1)
                temp1 = mul_data[i][size1] - '0';
                if (size2 > -1 )
                temp2 = sum[size2] - '0';
                one_sum = temp1 + temp2 + count;
                count = one_sum / 10;
                size1 --;
                size2 --;
                temp_sum += (one_sum % 10 + '0');
            }

            reverse(temp_sum.begin(), temp_sum.end());
            sum = temp_sum;
        }
        //去掉0
        int len = 0;
        for (int i = 0; i < sum.size()-1; i++)
        {
            if (sum[i] == '0')
                len++;
            else
                break;
        }
        sum.erase(0, len);
        return sum;
    }
};


int main()
{
    string num1 = "0";
    string num2 = "0";
    Solution().multiply(num1,num2);
}