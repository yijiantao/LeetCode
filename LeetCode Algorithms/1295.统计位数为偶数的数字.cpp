/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto _v: nums) {
            if (to_string(_v).size() % 2 == 0) res++;
        }
        return res;
    }
};
// @lc code=end

