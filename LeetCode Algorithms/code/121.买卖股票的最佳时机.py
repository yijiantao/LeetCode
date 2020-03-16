#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 方法一：暴力法（Time Limit Exceeded）
        # max_profit = 0
        # for _i in range(len(prices) - 1):
        #     for _j in range(_i + 1, len(prices)):
        #         profit = prices[_j] - prices[_i]
        #         if (profit > max_profit):
        #             max_profit = profit
        # return max_profit

        # 方法二
        min_value, max_profit = float('inf'), 0
        for _index in range(len(prices)):
            # 直接利用一个循环，找到最小的价钱 min_value 作为买入价，
            # 并找到在此买入价下的最大利润
            if (prices[_index] < min_value):
                min_value = prices[_index]
            elif (max_profit < prices[_index] - min_value):
                max_profit = prices[_index] - min_value
        return max_profit

# @lc code=end

