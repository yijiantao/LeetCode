#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#

# @lc code=start
class Solution:
    # def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
    @classmethod
    def intersection(self, nums1, nums2):
        result_list = []
        for _index in nums1:
            if _index in nums2 and _index not in result_list:
                result_list.append(_index)
        return result_list
# @lc code=end

print (Solution.intersection(nums1 = [4,9,5], nums2 = [9,4,9,8,4]))