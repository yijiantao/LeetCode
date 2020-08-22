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
            if (_v == 5) {
                res.push_back(_v);
            } else if (_v == 10) {

            } else if (_v == 20) {

            }
        }
        return !res.empty();
    }
};
// @lc code=end

