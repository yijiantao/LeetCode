/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, tmp = 0;
        for (int r=0; r<accounts.size(); ++r) {
            tmp =0;
            for (int c=0; c<accounts[r].size(); ++c)
                tmp += accounts[r][c];
            if (ans < tmp) ans = tmp;
        }
        return ans;
    }
};
// @lc code=end

