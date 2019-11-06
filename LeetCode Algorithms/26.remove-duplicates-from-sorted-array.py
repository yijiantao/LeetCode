#
# @lc app=leetcode.cn id=26 lang=python
#
# [26] 删除排序数组中的重复项
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _index = 0
        while _index < len(nums) - 1:
            if nums[_index] != nums[_index + 1]:
                _index += 1
            else:
                nums.pop(_index + 1)
        return len(nums)
        
# @lc code=end

