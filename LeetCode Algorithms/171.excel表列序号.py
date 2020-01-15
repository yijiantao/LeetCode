#
# @lc app=leetcode.cn id=171 lang=python3
#
# [171] Excel表列序号
#

# @lc code=start
import math
class Solution:
    # def titleToNumber(self, s: str) -> int:
    @classmethod
    def titleToNumber(self, s):
        words = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        result, length = 0, len(s)
        for _index in range(length):
            charIndex = words.index(s[_index]) + 1
            result += math.pow(26, length - 1 - _index) * charIndex

        return int(result)
# @lc code=end

print (Solution.titleToNumber(s = "A"))