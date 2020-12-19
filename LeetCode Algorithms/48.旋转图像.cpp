/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row_len = matrix.size(), col_len = matrix[0].size();
        // 矩阵转置
        for (int row_index = 0; row_index < row_len; ++row_index)
            for (int col_index = row_index+1; col_index < col_len; ++col_index)
                swap(matrix[row_index][col_index], matrix[col_index][row_index]);

        // 矩阵沿中轴线翻转
        for (int row_index = 0; row_index < row_len; ++row_index)
            for (int col_index = 0; col_index < col_len / 2; ++col_index)
                swap(matrix[row_index][col_index], matrix[row_index][col_len-col_index-1]);
    }
};
// @lc code=end

