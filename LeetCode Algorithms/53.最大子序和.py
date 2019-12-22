#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 动态规划 DP
        
        max_num = nums[0]
        for _index in range(1, len(nums)):
            nums[_index] = max(nums[_index], nums[_index] + nums[_index - 1])
            max_num = max(max_num, nums[_index])
        return max_num
# @lc code=end

