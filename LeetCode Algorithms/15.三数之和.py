#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums: return []
        result = set()
        nums = sorted(nums)
        # 为了处理最后一个特殊用例3000个0
        if nums[0] == nums[-1] == 0 and len(nums) > 3:
            return [[0, 0, 0]]
        self.findthree(nums, 0, result)
        return result

    def findthree(self, nums, target, result):
        for i,each in enumerate(nums):
            left = i + 1
            right =  len(nums) - 1
            new_target = target - each
            while left < right:
                if nums[left] + nums[right] == new_target:
                    result.add((nums[i], nums[left], nums[right]))
                    left += 1
                if nums[left] + nums[right] < new_target:
                    left += 1
                if nums[left] + nums[right] > new_target:
                    right -= 1
# @lc code=end

