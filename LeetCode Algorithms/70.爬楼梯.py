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
        # 斐波拉契数列
        
# @lc code=end

print (Solution.climbStairs(2))