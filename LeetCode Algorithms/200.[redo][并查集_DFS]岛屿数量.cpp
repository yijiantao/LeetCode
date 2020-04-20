/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    int n, m;
public:
    int numIslands(vector<vector<char>>& grid) {
        // int dx[] = {-1, 1, 0, 0};
        // int dy[] = {0, 0, -1, 1};
        if (!grid.size() || !grid[0].size()) return 0;
        // 方法 1. 染色 - DFS/BFS
        int res = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);    // 把该节点 i, j 所有的 "1" 都置为 “0” 会改变原数组 grid的值。
                    ++res;
                }
            }
        }
        return res;

        // 方法 2. 并查集
        // ...

    }

    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return ;
        grid[i][j] = '0';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
};
// @lc code=end

