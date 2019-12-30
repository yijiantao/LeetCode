#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 求众数
#

# @lc code=start
from collections import Counter
class Solution:
    # def majorityElement(self, nums: List[int]) -> int:
    @classmethod
    def majorityElement(self, nums):
        return Counter(nums).most_common(1)[0][0]
# @lc code=end

print (Solution.majorityElement(nums = [3,2,3]))