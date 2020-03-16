#
# @lc app=leetcode.cn id=414 lang=python3
#
# [414] 第三大的数
#

# @lc code=start
class Solution:
    @classmethod
    def thirdMax(self, nums) -> int:
        nums = sorted(nums, reverse=True)
        compare_num, count = float('inf'), 0
        for _index in nums:
            if compare_num > _index:
                compare_num = _index
                count += 1
                if count == 3: return compare_num
        return nums[0]
# @lc code=end

print (Solution.thirdMax(nums = [1, 2]))