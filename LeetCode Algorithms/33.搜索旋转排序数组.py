#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#

# @lc code=start
class Solution:
    @classmethod
    def search(self, nums, target: int) -> int:
        def judge_sort(arr_list):
            flag = True
            for _index in range(1, len(arr_list)):
                if arr_list[_index] < arr_list[_index - 1]:
                    flag = False
                    break
            return flag

        if target in nums:
            for _index, _value in enumerate(nums):
                if _value == target:
                    if len(nums) <= 2: return _index
                    if len(nums) > 2:
                        if judge_sort(nums[_index:] + nums[:_index]) or judge_sort(nums):
                            return _index


        return -1
# @lc code=end

print (Solution.search(nums = [4,5,6,7,0,1,2], target = 3))
print (Solution.search(nums = [3,1], target = 3))
print (Solution.search(nums = [1,3], target = 3))