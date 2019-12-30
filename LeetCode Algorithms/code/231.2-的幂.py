#
# @lc app=leetcode.cn id=231 lang=python3
#
# [231] 2的幂
#

# @lc code=start
class Solution:
    # def isPowerOfTwo(self, n: int) -> bool:
    @classmethod
    def isPowerOfTwo(self, n):
        if n < 1: return False
        while True:
            if n == 1: return True
            if n % 2 == 0:
                n //= 2
                continue
            else:
                return False
        
# @lc code=end

print (Solution.isPowerOfTwo(0))