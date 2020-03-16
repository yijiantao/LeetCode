#
# @lc app=leetcode.cn id=461 lang=python3
#
# [461] 汉明距离
#

# @lc code=start
class Solution:
    @classmethod
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
# @lc code=end

print (Solution.hammingDistance(x = 1, y = 4))