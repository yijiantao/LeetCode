#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3的幂
#

# @lc code=start
import math
class Solution:
    # def isPowerOfThree(self, n: int) -> bool:
    @classmethod
    def isPowerOfThree(self, n: int) -> bool:
        # round(x) 方法返回浮点数x的四舍五入值。
        # math.log(x) 方法返回x的自然对数，x > 0
        return n > 0 and 3 ** round(math.log(n, 3)) == n
# @lc code=end

print (Solution.isPowerOfThree(n = 27))