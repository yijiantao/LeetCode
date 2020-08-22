/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nums_5 = 0, nums_10 = 0;
        for (auto _v: bills) {
            if (_v == 5) {
                nums_5 += 1;
                continue;
            } else if (_v == 10) {
                if (nums_5 == 0) return false;
                nums_5 -= 1;
                nums_10 += 1;
            } else if (_v == 20) {

            }
        }
        return !res.empty();
    }
};
// @lc code=end

