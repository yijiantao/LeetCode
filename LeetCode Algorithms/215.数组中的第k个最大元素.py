#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
class Solution:
    # def findKthLargest(self, nums: List[int], k: int) -> int:
    @classmethod
    def findKthLargest(self, nums, k):
        return sorted(nums, reverse=True)[k-1]
# @lc code=end

print (Solution.findKthLargest(nums = [3,2,1,5,6,4], k = 2))