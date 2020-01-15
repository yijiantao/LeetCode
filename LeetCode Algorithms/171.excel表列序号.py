#
# @lc app=leetcode.cn id=171 lang=python3
#
# [171] Excel表列序号
#

# @lc code=start
import math
class Solution:
    # def titleToNumber(self, s: str) -> int:
    @classmethod
    def titleToNumber(self, s):

        # 理解这题前面可以先理解下十进制数的算法：
        # 比如 121 = 1*10（3-1）次幂+2*10（3-1-1）次幂+1*10（3-1-2）次幂
        # 所以，如果理解上面的算法，那么此题就很轻而易举了。
        # 26进制字母表，首先定义一个变量result来记录每次运算值，
        # 然后遍历字符串计算当前字符所在字母表的下标值 乘以 当前位次幂 赋值给变量result，，依次循环即可得到最终结果。。

        words = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        result, length = 0, len(s)
        for _index in range(length):
            charIndex = words.index(s[_index]) + 1
            result += math.pow(26, length - 1 - _index) * charIndex

        return int(result)
# @lc code=end

print (Solution.titleToNumber(s = "A"))