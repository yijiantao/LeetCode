/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

#include<bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    static constexpr int dx[4] = {-1, 0, 1, 0};    // 四个方向 横坐标：定义常量增量数组；
    static constexpr int dy[4] = {0, -1, 0, 1};    // 四个方向 纵坐标
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate
    {
        int x, y, step;
    };
    
    int n, m;
    vector<vector<int>> a;
    
    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y){    // 对于一个给定的区域 (x, y)(x,y) ，求它的「最近陆地区域」，可以使用宽度优先搜索思想
        // 实现 BFS 过程
        memset(vis, 0, sizeof vis);
        queue <Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            for (int i =0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) continue;
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) 
                    return f.step + 1;
                }
            }
        }
        return -1;    // 找不不到任何一个点是陆地区域则返回 -1
    }

    int maxDistance(vector<vector<int>>& grid) {
        int res = -1;
        this->n = grid.size();
        // C++里的两种访问顺序容器元素方式：grid[0]与 grid.at(0);
        // 例如访问容器c中元素，c.at(n)在下标越界的情况下会抛出out_of_range异常，而c[n]未定义、不报错，会随机访问内存地址输出，显然c.at(n)更安全。
        this->m = grid.at(0).size();
        a = grid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    res = max(res, findNearestLand(i, j));    // BFS 记录下它们的距离，然后在这些距离里面取一个最大值；
                }
            }
        }
        return res;
    }
};
// @lc code=end

constexpr int Solution::dx[4];
constexpr int Solution::dy[4];

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout << s.maxDistance(grid) << endl;
    return 0;
}
