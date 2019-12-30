#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 缺失数字
#

# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # 循环遍历list会超时！
        # （高斯累加，（首项+尾项）**项数//2） 减去 数组总和。
        return (len(nums) + 1) * len(nums) // 2 - sum(nums)
# @lc code=end
