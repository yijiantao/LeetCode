#
# @lc app=leetcode.cn id=205 lang=python3
#
# [205] 同构字符串
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        return [s.index(i) for i in s] == [t.index(i) for i in t]
# @lc code=end

