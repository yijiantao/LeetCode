/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));

        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        // map则是一个容器，里面存储的是 pair对象(序列对)。但存储的方式与vector<pair>这种 连续存储有所不同， map采用的是 二叉排序树存储pair，一般是红黑树。
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // 入队操作；
                    // emplace是调用构造函数，直接在容器中构造一个元素。而insert，push是拷贝操作，将元素拷贝到容器中。
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // BFS 模板
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni= i + dirs[d][0];
                int nj= j + dirs[d][1];

                if (ni >=0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }

        }
        return dist;
    }
};
// @lc code=end

