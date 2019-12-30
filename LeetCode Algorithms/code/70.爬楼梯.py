#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    # def climbStairs(self, n: int) -> int:
    @classmethod
    def climbStairs(self, n):
        if n <= 2: return n
        # 斐波拉契数列 + 动态规划算法
        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2
        for _index in range(3, n + 1):
            dp[_index] = dp[_index - 1] + dp[_index - 2]
        return dp[n]

# @lc code=end

print (Solution.climbStairs(33))