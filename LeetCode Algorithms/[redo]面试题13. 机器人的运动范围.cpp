#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res =0;
    bool checkSum(int _m, int _n, int _k) {
        int sum = 0;
        while (_m > 0 ) {
            sum += _m % 10;
            _m /= 10;
        }
        while (_n > 0 ) {
            sum += _n % 10;
            _n /= 10;
        }
        return sum <= _k;
    }

    void dfs(int cur_x, int cur_y, int m, int n, int k, vector<vector<int>>& vis) {
        if (cur_x >= m || cur_y >= n || cur_x < 0 || cur_y < 0 || !checkSum(cur_x, cur_y, k) || vis[cur_x][cur_y] == 1) return ;    // 剪枝  边界判断
        res ++;
        vis[cur_x][cur_y] = 1;
        dfs(cur_x + 1, cur_y, m, n, k, vis);
        dfs(cur_x - 1, cur_y, m, n, k, vis);
        dfs(cur_x, cur_y + 1, m, n, k, vis);
        dfs(cur_x, cur_y - 1, m, n, k, vis);
    }

    int movingCount(int m, int n, int k) {
        if (k == 0) return 1;
        vector<vector<int>> vis(m, vector<int>(n, 0));    // 矩阵 vis 保存访问过的节点，深度搜索所有节点
        dfs(0, 0, m, n, k, vis);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int m = 1, n = 2, k = 1;
    cout << s.movingCount(m, n, k) << endl;
    return 0;
}
