#
# @lc app=leetcode.cn id=168 lang=python3
#
# [168] Excel表列名称
#

# @lc code=start
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ''
        while n:
            # divmod()函数把除数和余数运算结果结合起来；
            # divmod(a, b)返回一个包含商和余数的元组(a // b, a % b)
            n, temp = divmod(n, 26)
            if temp == 0:
                n -= 1
                temp = 26
            # chr() )函数是输入一个整数【0，255】返回其对应的ascii码
            res = chr(temp + 64) + res
        return res
# @lc code=end

