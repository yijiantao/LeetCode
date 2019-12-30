#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for _index, _value in enumerate(nums):
            if target <= _value:
                return _index
        return _index + 1
# @lc code=end
