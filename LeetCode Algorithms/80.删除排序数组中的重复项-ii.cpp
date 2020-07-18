/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // [0,0,1,1,1,1,2,3,3]
        int nums_length = nums.size();
        if (nums_length < 3) return nums_length;
        int slow_p_index = 1;
        for (int fast_p_index = 2; fast_p_index < nums_length; ++fast_p_index) {
            if (nums[fast_p_index] != nums[slow_p_index - 1]) {
                nums[++slow_p_index] = nums[fast_p_index];    
            }
        }
        return slow_p_index + 1;
    }
};
// @lc code=end

