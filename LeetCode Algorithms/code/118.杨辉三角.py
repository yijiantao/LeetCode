#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#

# @lc code=start
class Solution:
    # def generate(self, numRows: int) -> List[List[int]]:
    @classmethod
    def generate(self, numRows):
        if numRows == 0: return []
        if numRows == 1: return [[1]]
        if numRows == 2: return [[1],[1,1]]
        result_list = [[1],[1,1]]
        for _row in range(3, numRows + 1):
            temp_list = [1]
            for _col in range(1, _row - 1):
                temp_list.append(result_list[_row - 2][_col - 1] + result_list[_row - 2][_col])
            temp_list.append(1)
            result_list.append(temp_list)
        return result_list
# @lc code=end
print (Solution.generate(numRows = 5))
