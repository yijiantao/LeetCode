/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int binary_search(int num, vector<int> &st) {
        int low = 0, high = st.size() - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (st[mid] == num)
                return mid;
            else if (st[mid] > num)
                high = mid - 1;
            else if (st[mid] < num)
                low = mid + 1;
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack_arr;
        if (nums.size() == 0) return 0;
        stack_arr.push_back(nums[0]);
        for (int _index = 1; _index < nums.size(); _index++){
            if (nums[_index] > stack_arr.back())
                stack_arr.push_back(nums[_index]);
            else {
                // for (int _i = 0; _i < stack_arr.size(); ++_i){
                //     if (stack_arr[_i] >= nums[_index]){
                //         stack_arr[_i] = nums[_index];
                //         break;
                //     }
                // }
                /* 优化：二分查找O(logn)， 上面写法是 O(n*n)*/
                int pos = binary_search(nums[_index], stack_arr);
                stack_arr[pos] = nums[_index];
            }
        }
        return stack_arr.size();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    /*
        可以使用栈+二分优化：O(nlogn)
            nums[i]大于栈中最后一个元素，就push到栈中
            nums[i]小于栈中最后一个元素，就遍历栈，用nums[i]替换第一个大于他的栈元素，这一步可以使用二分查找优化到 O(logn)
    */
    Solution s;
    vector<int> stack = {4,10,4,3,8,9};
    cout << s.lengthOfLIS(stack) << endl;
    return 0;
}
