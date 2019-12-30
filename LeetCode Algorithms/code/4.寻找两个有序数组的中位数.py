#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个有序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1_length = len(nums1)
        nums2_length = len(nums2)

        if nums1_length > nums2_length:
            return self.findMedianSortedArrays(nums2, nums1)

        half = (nums1_length + nums2_length + 1) // 2
        left = 0
        right = nums1_length

        while left < right:
            m1 = left + (right - left) // 2
            m2 = half - m1
            if nums1[m1] < nums2[m2 - 1]:
                left = m1 + 1
            else:
                right = m1
            
        m1 = left
        m2 = half - m1

        c1 = max(nums1[m1-1] if m1 > 0 else float("-inf"), nums2[m2-1] if m2 > 0 else float("-inf") )
        if (nums1_length + nums2_length) % 2 == 1:
            return c1
        c2 = min(nums1[m1] if m1 < nums1_length else float("inf"), nums2[m2] if m2 <nums2_length else float("inf"))
        return (c1 + c2) / 2
        
# @lc code=end

