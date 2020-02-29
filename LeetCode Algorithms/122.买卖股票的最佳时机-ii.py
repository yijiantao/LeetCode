#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for _index in range(1, len(prices)):
            tmp = prices[_index] - prices[_index - 1]
            if tmp > 0: profit += tmp
        return profit
# @lc code=end

