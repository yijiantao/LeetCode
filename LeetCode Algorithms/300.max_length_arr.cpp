/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack_arr;
        if (nums.size() == 0) return 0;
        stack_arr.push_back(nums[0]);
        for (int _index = 1; _index < nums.size(); _index++){
            if (nums[_index] > stack_arr.back())
                stack_arr.push_back(nums[_index]);
            else {
                for (int _i = 0; _i < stack_arr.size(); ++_i){
                    if (stack_arr[_i] >= nums[_index]){
                        stack_arr[_i] = nums[_index];
                        break;
                    }
                }
            }
        }
        for (int _v: stack_arr)
            cout << _v << endl;
        return stack_arr.size();
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> stack = {4,10,4,3,8,9};
    cout << s.lengthOfLIS(stack) << endl;
    return 0;
}
