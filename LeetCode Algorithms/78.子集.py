#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:
    @classmethod
    def subsets(self, nums):
        sub_list = [[]]
        for i in range(len(nums)):
            for j in range(len(sub_list)):
                temp_sub_list = sub_list[j] + [nums[i]]
                if temp_sub_list not in sub_list:
                    sub_list.append(temp_sub_list)
        return sub_list
# @lc code=end

print (Solution.subsets(nums = [1,2,3]))