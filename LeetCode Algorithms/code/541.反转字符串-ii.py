#
# @lc app=leetcode.cn id=541 lang=python3
#
# [541] 反转字符串 II
#

# @lc code=start
class Solution:
    @classmethod
    def reverseStr(self, s: str, k: int) -> str:
        res, flag = '', 1
        for _index in range(0, len(s), k):
            if flag:
                res += s[_index:_index+k][::-1]
                flag = 0
            else:
                res += s[_index:_index+k]
                flag = 1
        return res
# @lc code=end

print (Solution.reverseStr(s = "abcdefg", k = 2))