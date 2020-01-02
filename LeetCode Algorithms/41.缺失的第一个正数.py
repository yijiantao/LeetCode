#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        _index = 1
        while True:
            if _index not in nums: break
            _index += 1
        return _index
# @lc code=end

