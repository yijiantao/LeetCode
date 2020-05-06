/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp数组，每个元素代表到当前天数最少钱数，为下标方便对应，多加一个 0 位置
        vector<int> dp(days.back() + 1, 0);
        
        int days_index = 0;
        for (int _i = 1; _i < dp.size(); ++_i) {
            if (_i != days[days_index]) {
                dp[_i] = dp[_i - 1];   // 该天不出行，则花费等于前一天的开销
            }
            else {
                dp[_i] = min(min(dp[max(0, _i - 1)] + costs[0], dp[max(0, _i - 7)] + costs[1]), dp[max(0, _i - 30)] + costs[2]);
                ++days_index;
            }
        }
        return dp.back();
    }
};
// @lc code=end

