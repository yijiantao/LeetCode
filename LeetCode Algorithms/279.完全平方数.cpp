/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int numSquares(int n) {
        // dp 状态转移方程
        // dp[n] = min(dp[n], dp[n-i*i]+1)

        vector <int> dp(n+1);
        for (int _index=0; _index <= n; ++_index){
            dp[_index] = _index;
            for (int _i = 1; _i * _i <= _index; ++_i){
                dp[_index] = min(dp[_index], dp[_index - _i * _i] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main()
{
    int n;
    Solution s;
    int count = s.numSquares(n=12);
    cout<<count<<endl;
    return 0;
}