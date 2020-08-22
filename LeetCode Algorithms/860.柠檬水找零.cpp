/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> res;
        for (auto _v: bills) {
            if (res.empty() && (_v - 5) == 0) {
                res.push_back();
            }
        }
        return !res.empty();
    }
};
// @lc code=end

