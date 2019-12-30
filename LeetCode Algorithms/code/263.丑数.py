#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#

# @lc code=start
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0: return False
        while num % 2 == 0: num >>= 1 # 右移运算符，右移一位相当于除以二; (左移一位，相当于乘以二)
        while num % 3 == 0: num /= 3
        while num % 5 == 0: num /= 5
        return num == 1
        
# @lc code=end
