/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int ans = 1;
        if (n < 2) return n;
        else return fib(n - 1) + fib(n - 2);
    }
};
// @lc code=end
