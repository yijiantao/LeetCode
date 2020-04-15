/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

/*
    ## 广度优先搜索
    思路：
    对于 「Tree 的 BFS」 （典型的「单源 BFS」） 大家都已经轻车熟路了：

    首先把 root 节点入队，再一层一层无脑遍历就行了。
    对于 「图 的 BFS」 （「多源 BFS」） 做法其实也是一样滴～，与 「Tree 的 BFS」的区别注意以下两条就 ok 辣～

    Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；
    Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过哦！并且为了防止某个节点多次入队，需要在其入队之前就将其设置成已访问！【 看见很多人说自己的 BFS 超时了，坑就在这里哈哈哈
    做法：
    根据上述思路，本题怎么做就很简单了：

    首先把每个源点 00 入队，然后从各个 00 同时开始一圈一圈的向 11 扩散（每个 11 都是被离它最近的 00 扩散到的 ），扩散的时候可以设置 int[][] dist 来记录距离（即扩散的层次）并同时标志是否访问过。对于本题是可以直接修改原数组 int[][] matrix 来记录距离和标志是否访问的，这里要注意先把 matrix 数组中 1 的位置设置成 -1 （设成Integer.MAX_VALUE啦，m * n啦，10000啦都行，只要是个无效的距离值来标志这个位置的 1 没有被访问过就行辣~）
    复杂度分析：

    每个点入队出队一次，所以时间复杂度：O(n * m)O(n∗m)
    虽然我们是直接原地修改的原输入数组来存储结果，但最差的情况下即全都是 00 时，需要把 m * nm∗n 个 00 都入队，因此空间复杂度是 O(n * m)O(n∗m)

    作者：sweetiee
    链接：https://leetcode-cn.com/problems/01-matrix/solution/2chong-bfs-xiang-jie-dp-bi-xu-miao-dong-by-sweetie/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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

