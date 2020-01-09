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
                算法思路：
                left永远指向第一个为0的位置，right逢0加一后移一位，直到碰到下一个不为0的数，跟nums[left]交换，然后left，right同时加一，重复操作
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