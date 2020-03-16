#
# @lc app=leetcode.cn id=89 lang=python3
#
# [89] 格雷编码
#

# @lc code=start
class Solution:
    @classmethod
    def grayCode(self, n):
        # 公式法
        res = [0 for _ in range(2 ** n)]
        for _index in range(1, 2 ** n):
            res [_index] = (_index >> 1) ^ _index

        return res

# @lc code=end

print (Solution.grayCode(n = 0))