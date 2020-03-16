#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#

# @lc code=start
class Solution:
    @classmethod
    def isValidSudoku(self, board):
        row_mark_dict = {}
        col_mark_dict = {}
        box_mark_dict = {}

        for row_index in range(9):
            for col_index in range(9):
                if board[row_index][col_index] == '.':
                    continue

                if row_index not in row_mark_dict.keys():
                    row_mark_dict[row_index] = []
                if col_index not in col_mark_dict.keys():
                    col_mark_dict[col_index] = []

                box_row_index = row_index // 3
                box_col_index  = col_index // 3
                if f'{box_row_index}_{box_col_index}' not in box_mark_dict.keys():
                    box_mark_dict[f'{box_row_index}_{box_col_index}'] = []

                if board[row_index][col_index] not in row_mark_dict[row_index]:
                    row_mark_dict[row_index].append(board[row_index][col_index])
                else:
                    return False

                if board[row_index][col_index] not in col_mark_dict[col_index]:
                    col_mark_dict[col_index].append(board[row_index][col_index])
                else:
                    return False

                if board[row_index][col_index] not in box_mark_dict[f'{box_row_index}_{box_col_index}']:
                    box_mark_dict[f'{box_row_index}_{box_col_index}'].append(board[row_index][col_index])
                else:
                    return False
        print (box_mark_dict)
        return True
# @lc code=end

print (Solution.isValidSudoku(board = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))