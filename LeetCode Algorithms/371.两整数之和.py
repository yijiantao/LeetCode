#
# @lc app=leetcode.cn id=371 lang=python3
#
# [371] 两整数之和
#

# @lc code=start
class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 方法一：
        # return sum([a,b])

        # 方法二：
        # 解题思路
        # a ^ b 计算不进为的和
        # a & b 计算出进位
        # ((a & b) << 1) 把进位左移，赋值给b，继续用进位进行异或操作，求不进位的和
        MASK = 0x100000000
        # 整型最大值
        MAX_INT = 0x7FFFFFFF
        MIN_INT = MAX_INT + 1
        while b != 0:
            # 计算进位
            carry = (a & b) << 1 
            # 取余范围限制在 [0, 2^32-1] 范围内
            a = (a ^ b) % MASK
            b = carry % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)   

# @lc code=end

