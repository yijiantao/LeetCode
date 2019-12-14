#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left_index, right_index, res = 0, len(height) - 1, 0
        while left_index < right_index:
            if height[left_index] < height[right_index]:
                res = max(res, height[left_index] * (right_index - left_index))
                left_index += 1
            else:
                res = max(res, height[right_index] * (right_index - left_index))
                right_index -= 1
        return res
# @lc code=end

