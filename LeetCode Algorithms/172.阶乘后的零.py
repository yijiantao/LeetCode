#
# @lc app=leetcode.cn id=172 lang=python3
#
# [172] 阶乘后的零
#

# @lc code=start
import math
class Solution:
    # def trailingZeroes(self, n: int) -> int:
    @classmethod
    def trailingZeroes(self, n):
        res =  str(math.factorial(n))[::-1]
        for _index, _value in enumerate(res):
            if _value != '0': break
        return res, _index
# @lc code=end

print (Solution.trailingZeroes(n = 10000))