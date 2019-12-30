#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        flag = 1 if x > 0 else -1
        result = flag * int((str(abs(x)))[::-1])
        return result if (2 ** 31 - 1) >= result >= (-2 ** 31) else 0  
# @lc code=end

