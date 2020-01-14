#
# @lc app=leetcode.cn id=190 lang=python3
#
# [190] 颠倒二进制位
#

# @lc code=start
class Solution:
    # def reverseBits(self, n: int) -> int:
    @classmethod
    def reverseBits(self, n):
        # res = bin(n)[2:]    #将n转换成2进制形式，并且去除前缀0b
        # res = res.zfill(32)    #在二进制左侧填充0，使得长度为32位
        # res = res[::-1]    # 反转二进制
        # int(res,base=2)    # 将二进制转换为整数

        return int(bin(n)[2:].zfill(32)[::-1], base=2)
# @lc code=end

print (Solution.reverseBits(0x00000010100101000001111010011100))
