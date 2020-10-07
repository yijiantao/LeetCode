/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include<bits/stdc++.h>

// @lc code=start
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        // int left_index = 0, right_index = nums.size() - 1;
        // for (int _index = 0; _index <= right_index; ++_index) {
        //     if (nums[_index] == 0) std::swap(nums[left_index++], nums[_index]);
        //     if (nums[_index] == 2) std::swap(nums[right_index--], nums[_index--]);
        // }
        std::sort(nums.begin(), nums.end());
    }
};
// @lc code=end

// int main(int argc, char const *argv[])
// {
//     Solution s;
//     std::vector<int> nums = {2,0,1};
//     s.sortColors(nums);
//     return 0;
// }
