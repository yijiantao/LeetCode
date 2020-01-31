#
# @lc app=leetcode.cn id=214 lang=python3
#
# [214] 最短回文串
#

# @lc code=start
class Solution:
    # def shortestPalindrome(self, s: str) -> str:
    @classmethod
    def shortestPalindrome(self, s):
        # 方法一、暴力法求解：
        # r = s[::-1]
        # isHuiWen = lambda x: True if x == x[::-1] else False
        # if isHuiWen(s): return s
        # for _index in range(len(s) + 1):
        #     if isHuiWen(r[:_index] + s): return r[:_index] + s

        # 方法二、KMP算法
        def get_PMT_table(p):    # 生成 Partial Match Table 部分匹配表
            i, j, next_arr[0] = 0, -1, -1


# @lc code=end

print (Solution.shortestPalindrome(s = "dcbabcd"))