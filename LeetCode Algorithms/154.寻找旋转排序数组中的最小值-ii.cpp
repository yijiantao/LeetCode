/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 
        int res = nums[0];
        for (int _index = 1; _index < nums.size(); ++_index) 
            if (nums[_index-1] > nums[_index]) return nums[_index];
        return res;
    }
};
// @lc code=end

