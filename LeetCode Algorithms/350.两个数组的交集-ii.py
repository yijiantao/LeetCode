#
# @lc app=leetcode.cn id=350 lang=python3
#
# [350] 两个数组的交集 II
#

# @lc code=start
class Solution:
    @classmethod
    def intersect(self, nums1, nums2):
        res = []
        _index_1, _index_2 = 0, 0
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)
        
        while True:
            if _index_1 == len(nums1) or _index_2 == len(nums2):
                break
            if nums1[_index_1] == nums2[_index_2]:
                res.append(nums1[_index_1])
                _index_1 += 1
                _index_2 += 1
            elif nums1[_index_1] > nums2[_index_2]:
                _index_2 += 1
            else: _index_1 += 1

        return res

# @lc code=end

print (Solution.intersect([1,2,2,1], [2,2]))