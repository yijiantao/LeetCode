#
# @lc app=leetcode.cn id=191 lang=python3
#
# [191] 位1的个数
#

# @lc code=start
class Solution:
    # def hammingWeight(self, n: int) -> int:
    @classmethod
    def hammingWeight(self, n):
        # python 内置 bin() 函数
        ##  输入： int 或者 long int 数字
        ##  输出：字符串
        return bin(n).count('1')
# @lc code=end
