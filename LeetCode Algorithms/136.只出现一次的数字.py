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
        # return 2 * sum(set(nums)) - sum(nums)

        # 方法三： 异或运算！
        ## 如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位
        ## a ^ 0 = a
        ##如果我们对相同的二进制位做 XOR 运算，返回的结果是 0
        ## a ^ a = 0
        ## 所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。
        a = 0
        for i in nums:
            a ^= i
        return a

# @lc code=end

print (Solution.singleNumber(nums = [4,1,2,1,2]))