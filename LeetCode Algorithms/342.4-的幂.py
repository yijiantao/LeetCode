#
# @lc app=leetcode.cn id=342 lang=python3
#
# [342] 4的幂
#

# @lc code=start
import math
class Solution:
    # def isPowerOfFour(self, num: int) -> bool:
    @classmethod
    def isPowerOfFour(self, num):
        return num > 0 and 4 ** round(math.log(num, 4)) == num
# @lc code=end

print (Solution.isPowerOfFour(num = 5))
