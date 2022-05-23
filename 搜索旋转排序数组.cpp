#include"global.h"

class Solution {
public:
    int index = -1;
    int search(vector<int>& nums, int target) {
        binarymath(nums, target, 0, nums.size() - 1);
        return index;
    }
    void binarymath(vector<int>& nums, int target, int min, int max)
    {
        if (max < min)
            return;
        int mid = (max + min) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            return;
        }
        //说明中间在倒序部分
        if (nums[mid] >= nums[min] && nums[mid] > nums[max])
        {
            //左边部分正常二分查找
            if (target < nums[mid] && target >= nums[min])
                binarymath(nums, target, min, mid - 1);
            //右边部分直接递归
            binarymath(nums, target, mid+1, max);
        }
        //说明中间不在倒序部分
        else
        {
            //右边部分正常二分查找
            if (target > nums[mid] && target <= nums[max])
                binarymath(nums, target, mid + 1, max);
            //左边部分递归
            binarymath(nums, target, min, mid - 1);
        }

    }
};

int main()
{
    vector<int> nums = { 3,1 };
    int target = 1;
    Solution().search(nums, target);
}