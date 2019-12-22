#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 分治法：其实最大子序要么在左半边，要么在右半边，要么穿过中间
        # 对于左右两边的子序列情况是一样的，可用递归处理求出
        # 穿过中间部分的子序列可以直接计算出来
# @lc code=end

