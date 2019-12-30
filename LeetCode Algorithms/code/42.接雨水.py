#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:

        water_volume = 0
        left, right = 0, len(height) - 1
        left_max, right_max = 0, 0
        while (left < right):
            if (height[left] < height[right]):
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water_volume += (left_max - height[left])
                left += 1

            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water_volume += (right_max - height[right])
                right -= 1
        return water_volume 

# @lc code=end
