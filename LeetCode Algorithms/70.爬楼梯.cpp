/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int _index = 3; _index < n + 1; ++_index) dp[_index] = dp[_index - 1] + dp[_index - 2];
        return dp[n];

    }
};
// @lc code=end

