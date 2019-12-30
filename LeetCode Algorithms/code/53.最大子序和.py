#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    # def maxSubArray(self, nums: List[int]) -> int:
    @ classmethod
    def maxSubArray(self, nums):
        # 动态规划 DP
        # 分析存在如下两种情况：
        ## 1.当前元素为子序起始点
        ## 2.当前元素为子序中间或结尾点
        ## 因此：nums[i] = nums[i]和nums[i] + nums[i -1]（第二种情况）中的最大值

        max_num = nums[0]
        for _index in range(1, len(nums)):
            nums[_index] = max(nums[_index], nums[_index] + nums[_index - 1])
            max_num = max(max_num, nums[_index])
        print (nums)
        return max_num
# @lc code=end

print (Solution.maxSubArray(nums = [-2,1,-3,4,-1,2,1,-5,4]))