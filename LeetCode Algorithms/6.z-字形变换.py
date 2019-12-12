#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        result_list = ['' for _ in range(numRows)]
        flag = 0
        for _index, _val in enumerate(s):
            result_list[abs(flag)] += _val
            if flag == 0 or flag == numRows - 1: flag = -flag
            flag += 1
        return ''.join(result_list)
# @lc code=end

