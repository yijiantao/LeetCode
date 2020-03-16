#
# @lc app=leetcode.cn id=59 lang=python3
#
# [59] 螺旋矩阵 II
#

# @lc code=start


class Solution:
    @classmethod
    def generateMatrix(self, n):
        matrix = [[0] * n for _ in range(n)]
        row_flag = [0, 1, 0, -1]
        col_flag = [1, 0, -1, 0]
        next_row, next_col, next_flag = 0, 0, 0
        for _index in range(1, n * n + 1):
            print(next_flag, next_row, next_col)
            matrix[next_row][next_col] = _index

            if (next_row == n - 1 and next_col == 0) or (next_row == n - 1 and next_col == n - 1) or (next_row == 0 and next_col == n - 1) or matrix[next_row + row_flag[next_flag]][next_col + col_flag[next_flag]] != 0:
                # 进入拐点，开始变方向
                next_flag = (next_flag + 1) % 4

            next_row = next_row + row_flag[next_flag]
            next_col = next_col + col_flag[next_flag]
        return matrix
# @lc code=end


print(Solution.generateMatrix(n=3))
