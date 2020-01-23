#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
    # def searchRange(self, nums: List[int], target: int) -> List[int]:
    @classmethod
    def searchRange(self, nums, target):
        # 常规方法一：
        local_res = [-1, -1]
        for _index, _value in enumerate(nums):
            if _value == target:
                if local_res[0] == -1:
                    local_res[0] = _index
                else:
                    local_res[1] = _index
        if local_res[0] != -1 and local_res[1] == -1: local_res[1] = local_res[0]
        return local_res

        # 
        
# @lc code=end

print (Solution.searchRange(nums = [1, 3], target = 1))