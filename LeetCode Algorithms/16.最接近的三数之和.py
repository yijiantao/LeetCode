#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#

# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # 左右指针移动过程中记录与target绝对值最小的cur_res
        # 排序好nums数组
        nums.sort()
        length = len(nums)
        res = float('inf')    # res等于正无穷大
        for _index in range(length):
            if _index > 0 and nums[_index] == nums[_index - 1]:
                continue
            left, right = _index + 1, length - 1
            while left < right:
                cur_res = nums[_index] + nums[left] + nums[right]    # 求值
                if cur_res == target: return target    # 剪枝
                if abs(res - target) > abs(cur_res - target):
                    res = cur_res
                if cur_res > target:
                    right -= 1
                elif cur_res < target:
                    left += 1
        return res
# @lc code=end

