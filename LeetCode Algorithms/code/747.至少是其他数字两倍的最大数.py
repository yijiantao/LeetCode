#
# @lc app=leetcode.cn id=747 lang=python3
#
# [747] 至少是其他数字两倍的最大数
#

# @lc code=start
class Solution:
    @classmethod
    def dominantIndex(self, nums):
        max_num = max(nums)
        for _value in nums:
            if max_num == _value: continue
            if max_num // 2 < _value: return -1
        return nums.index(max_num)
# @lc code=end

print (Solution.dominantIndex(nums = [1, 2, 3, 4]))