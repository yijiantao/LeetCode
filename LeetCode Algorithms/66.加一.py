#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 方法一：
        return [int(_index) for _index in str(int(''.join([str(_index) for _index in digits])) + 1)]
        # 方法二:
        if not digits: return [0]
        jinwei_flag = 0
        digits[-1] += 1
        for _index in range(len(digits) - 1, -1, -1):
            digits[_index] += jinwei_flag
            jinwei_flag = digits[_index] // 10
            digits[_index] %= 10
        if jinwei_flag != 0: digits.insert(0, jinwei_flag)
        return digits
# @lc code=end
