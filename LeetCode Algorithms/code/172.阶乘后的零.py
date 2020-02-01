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
        # 直接求阶乘，再统计的方法，当 n = 10000时 “Time Limit Exceeded”
        # res =  str(math.factorial(n))[::-1]
        # for _index, _value in enumerate(res):
        #     if _value != '0': break
        # return res, _index

        # 方法二：
        # 计算阶乘后面0的个数就是计算因数中有多少个5，所以计算5的个数即为5的个数
        if n < 5: return 0
        return int(n / 5 + Solution.trailingZeroes(n / 5))
# @lc code=end

print (Solution.trailingZeroes(n = 6))