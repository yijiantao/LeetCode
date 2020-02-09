#
# @lc app=leetcode.cn id=405 lang=python3
#
# [405] 数字转换为十六进制数
#

# @lc code=start
class Solution:
    @classmethod
    def toHex(self, num: int) -> str:
        return hex(num & 0xFFFFFFFF)[2:]
# @lc code=end

print (Solution.toHex(num = 26))