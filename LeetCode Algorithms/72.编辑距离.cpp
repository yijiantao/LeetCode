/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2 +1, 0));
        // 第一行
        for (int j = 1; j < n2 + 1; ++j)
            dp[0][j] = dp[0][j-1] + 1;
        // 第一列
        for (int i = 1; i < n1 + 1; ++i)
            dp[i][0] = dp[i-1][0] + 1;
        for (int i = 1; i < n1 + 1; ++i)
            for (int j = 1; j < n2 + 1; ++j){
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                }
            }
                
        return dp[n1][n2];
    }
};
// @lc code=end

