/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int temp_x = x;
        long res = temp_x % 10;
        for (; temp_x /= 10;) res = res*10 + temp_x % 10;
        return x >= 0 && res == x;
    }
};
// @lc code=end

