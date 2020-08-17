/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, tmp_res = 0;
        for (auto _v: nums) {
            if (_v == 0) tmp_res = 0;
            if (_v == 1) tmp_res += 1;
            if (tmp_res > res) {
                res = tmp_res;
            }
        }
        return res;
    }
};
// @lc code=end

