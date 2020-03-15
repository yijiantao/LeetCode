/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j){
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
            return 0;
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, -1, 1};
        int dj[4] = {1, -1, 0, 0};
        int res = 1;
        for (int index = 0; index != 4; ++index){
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            res += dfs(grid, next_i, next_j);
        }
        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i=0; i != grid.size(); ++i)
            for (int j=0; j != grid[0].size(); ++j)
                res = max(res, dfs(grid, i, j));
        return res ? res : 0;
    }
};
// @lc code=end

