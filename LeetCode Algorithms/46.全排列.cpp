/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        // 所有数都填完了
        if (first == len) {
            
            // push_back()函数向容器中加入一个临时对象（右值元素）时， 首先会调用构造函数生成这个对象，然后条用拷贝构造函数将这个对象放入容器中， 最后释放临时对象。
            // 但是emplace_back()函数向容器中中加入临时对象， 临时对象原地构造，没有赋值或移动的操作。
            // emplace_back()函数要比push_back()函数要快一倍。
            res.emplace_back(output);    // emplace_back 能就地通过参数构造对象，不需要拷贝或者移动内存，相比push_back能更好地避免内存的拷贝与移动。
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
};
// @lc code=end

