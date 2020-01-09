#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    # def moveZeroes(self, nums: List[int]) -> None:
    @classmethod
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        left, right = 0, 0
        while right < len(nums):
            """
                
            """
            if nums[left] != 0 and nums[right] != 0:
                left += 1; right += 1; continue
            if nums[left] == 0 and nums[right] != 0:
                    nums[left], nums[right] = nums[right], nums[left]
                    left += 1; right += 1; continue
            if nums[left] != 0: left += 1; right += 1; continue
            if nums[left] == 0: right += 1
        return nums
        
# @lc code=end

print (Solution.moveZeroes(nums = [4,2,4,0,0,3,0,5,1,0]))