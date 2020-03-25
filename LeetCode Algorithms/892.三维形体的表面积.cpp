/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int row_length = grid.size(), col_length = grid[0].size();
        if (row_length == 0 || col_length == 0) return res;
        for (int _i =0; _i < row_length; ++_i){
            for (int _j =0; _j < col_length; ++_j){
                if (grid[_i][_j] <= 0) continue;
                // 一个柱体中：2个底面 + 所有的正方体都贡献了4个侧表面积 
                res += (grid[_i][_j] * 4 + 2);
                // 隔壁行有多少个正方体相邻，则需要减去min（相邻数） * 2个面
                res -= _i > 0 ? min(grid[_i][_j], grid[_i - 1][_j]) * 2 : 0;
                // 隔壁列有多少个正方体相邻，则需要减去min（相邻数） * 2个面
                res -= _j > 0 ? min(grid[_i][_j], grid[_i][_j - 1]) * 2 : 0;
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid  {{1,1,1},{1,0,1},{1,1,1}};
    cout <<s.surfaceArea(grid) << endl;
    return 0;
}
