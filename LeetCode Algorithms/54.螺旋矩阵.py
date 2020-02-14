#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#

# @lc code=start
class Solution:
    @classmethod
    def spiralOrder(self, matrix):
        """
            逆时针旋转矩阵：先转置，再上下翻转。
            顺时针旋转矩阵：先上下翻转，再转置。
        """
        res = []
        while matrix:
            res += matrix.pop(0)
            matrix = list(zip(*matrix))[::-1]
            # print (res)
        return res

# @lc code=end

print (Solution.spiralOrder(matrix=[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]))