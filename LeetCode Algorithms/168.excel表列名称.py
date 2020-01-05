#
# @lc app=leetcode.cn id=168 lang=python3
#
# [168] Excel表列名称
#

# @lc code=start
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ''
        while n:
            n, temp = divmod(n, 26)
            if temp == 0:
                n -= 1
                temp = 26
            res = chr(temp + 64) + res
        return res
# @lc code=end

