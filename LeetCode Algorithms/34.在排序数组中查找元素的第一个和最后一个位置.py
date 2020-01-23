#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
    # def searchRange(self, nums: List[int], target: int) -> List[int]:
    def binaraySearch(self, nums, target, left):
        begin_index, end_index = 0, len(nums)
        while begin_index < end_index:
            mid_index = (begin_index + end_index) // 2
            if nums[mid_index] > target or (left and target == nums[mid_index]):
                end_index = mid_index
            else:
                begin_index = mid_index + 1

        return begin_index
    
    def searchRange(self, nums, target):
        """ 常规方法一：算法时间复杂度 O(n) 级别
        local_res = [-1, -1]
        for _index, _value in enumerate(nums):
            if _value == target:
                if local_res[0] == -1:
                    local_res[0] = _index
                else:
                    local_res[1] = _index
        if local_res[0] != -1 and local_res[1] == -1: local_res[1] = local_res[0]
        return local_res
        """
        # 方法二：二分查找 - 算法时间复杂度是 O(log n) 级别
        left_index = self.binaraySearch(nums, target, True)

        if left_index == len(nums) or nums[left_index] != target:
            return [-1, -1]

        return [left_index, self.binaraySearch(nums, target, False) - 1]
# @lc code=end

# print (Solution.searchRange(nums = [1, 3], target = 1))
solution = Solution()
print (solution.searchRange(nums = [5,7,7,8,8,10], target = 8))