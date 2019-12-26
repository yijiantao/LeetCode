#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

# @lc code=start
class Solution:
    # def singleNumber(self, nums: List[int]) -> int:
    @classmethod
    def singleNumber(self, nums):
        # 如下方法会超时。。。。 没看清题意，，，
        # return [ _index for _index in nums if nums.count(_index) == 1][0]

        # 方法二
        # 除了某个元素只出现一次以外，其余每个元素均出现两次。
        return 2 * sum(set(nums)) - sum(nums)

# @lc code=end

print (Solution.singleNumber(nums = [4,1,2,1,2]))