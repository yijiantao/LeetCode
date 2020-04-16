/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for (int _index = 0; _index < intervals.size(); ++_index) {
            int left = intervals[_index][0], right = intervals[_index][1];
            if (!res.size() || res.back()[1] < left) {    // a[i].end < a[k].start 不能合并，插入原始数据区间
                res.push_back({left, right});
            }
            else {    // 能合并
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
};
// @lc code=end

