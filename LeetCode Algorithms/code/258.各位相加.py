#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#

# @lc code=start
class Solution:
    def addDigits(self, num: int) -> int:
        # 数学归纳法- 找规律
        if num > 9:
            num %= 9
            if num == 0:
                return 9
        return num
        
# @lc code=end
