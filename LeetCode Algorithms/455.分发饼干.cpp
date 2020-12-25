/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_nums = g.size(), cook_nums = s.size();
        int count =0;
        for (int i = 0, j = 0; i < child_nums && j < cook_nums; i++, j++) {
            while (j < child_nums && g[i] > s[j]) j++;
            if (j < child_nums) count ++;
        }
        return count;
    }
};
// @lc code=end

