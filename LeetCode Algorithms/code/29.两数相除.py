#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#

# @lc code=start
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = (dividend < 0) is (divisor < 0)      # 正负符号标志
        dividend, divisor = abs(dividend), abs(divisor)

        res = 0
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                res += i
                # 左移运算符，运算数的各二进位全部左移若干位，由 << 右边的数字指定了移动的位数，高位丢弃，低位补0
                # 左移一位，相当于乘以2
                i <<= 1
                temp <<= 1
        if not flag:
            res = -res
        return min(max(-2147483648, res), 2147483647)

# @lc code=end

