/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_res = 0, left_index =0, right_index = height.size();
        while (left_index <= right_index) {
            if (height[left_index] < height[right_index]) {
                max_res = max(max_res, height[left_index] * (right_index - left_index));
                left_index ++;
            }
            else {
                max_res = max(max_res, height[right_index] * (right_index - left_index));
                right_index --;
            }
        }
        return max_res;
    }
};
// @lc code=end

