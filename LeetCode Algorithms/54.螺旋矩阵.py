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
            方法一 [巧妙]：
            逆时针旋转矩阵：先转置，再上下翻转。
            顺时针旋转矩阵：先上下翻转，再转置。
        """
        # res = []
        # while matrix:
        #     res += matrix.pop(0)
        #     matrix = list(zip(*matrix))[::-1]
        #     print (res)
        # return res

        # 方法二：常规方法
        if not matrix: return []
        row, col = len(matrix), len(matrix[0])
        flag_matrix = [[False] * col for _ in matrix]
        res = []

        row_flag = [0, 1, 0, -1]    # 矩阵行索引遍历的四次方向：右，下，左，上
        col_flag = [1, 0, -1, 0]    # 矩阵列索引遍历的四次方向：右，下，左，上

        _row_index = _col_index = fangxiang_flag = 0
        for _ in range(row * col):
            res.append(matrix[_row_index][_col_index])
            flag_matrix[_row_index][_col_index] = True

            next_row_index = _row_index + row_flag[fangxiang_flag]
            next_col_index = _col_index + col_flag[fangxiang_flag]

            if 0 <= next_row_index < row and 0 <= next_col_index < col and not flag_matrix[next_row_index][next_col_index]:
                # 遍历整个矩阵，下一步候选移动位置是 (next_row_index, next_col_index)。
                # 如果这个候选位置在矩阵范围内并且没有被访问过，
                # 那么它将会变成下一步移动的位置
                _row_index, _col_index = next_row_index, next_col_index
            else:
                # 否则，将前进方向顺时针旋转之后再计算下一步的移动位置。
                fangxiang_flag = (fangxiang_flag + 1) % 4
                _row_index = _row_index + row_flag[fangxiang_flag]
                _col_index = _col_index + col_flag[fangxiang_flag]
        return res
# @lc code=end

print (Solution.spiralOrder(matrix=[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]))