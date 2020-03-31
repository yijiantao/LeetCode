/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    //快速排序（从小到大）
    void quickSort(int left, int right, vector<int>& arr)
    {
        if(left >= right)    // 递归边界条件
            return;
        int i, j, base, temp;
        i = left, j = right;
        base = arr[left];  //取最左边的数为基准数
        while (i < j)
        {
            while (arr[j] >= base && i < j)
                j--;
            while (arr[i] <= base && i < j)
                i++;
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //基准数归位
        arr[left] = arr[i];
        arr[i] = base;
        quickSort(left, i - 1, arr);//递归左边
        quickSort(i + 1, right, arr);//递归右边
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size() - 1, nums);
        return nums;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {};
    for (int _v: s.sortArray(nums)) cout << _v << endl;
    return 0;
}
