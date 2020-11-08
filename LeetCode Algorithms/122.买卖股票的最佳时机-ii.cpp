/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, tmp = 0;
        for (int _index = 1; _index < prices.size(); ++_index) {
            tmp = prices[_index] - prices[_index - 1];
        }
    }
};
// @lc code=end

