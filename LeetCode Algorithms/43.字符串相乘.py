#
# @lc app=leetcode.cn id=43 lang=python3
#
# [43] 字符串相乘
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
            if num1 == '0' or num2 == '0':
                return '0'
            if len(num1) < len(num2):
                num1, num2 = num2, num1
            
            res = 0
            jinwei_flag = 0

            num1 = num1[::-1]
            num2 = num2[::-1]

            for _index, _value in enumerate(num2):
                temp = 0
                for _i, _v in enumerate(num1):
                    temp += int(_value) * int(_v) * 10 ** _i
                res += temp * 10 ** _index

            return str(res)
# @lc code=end

