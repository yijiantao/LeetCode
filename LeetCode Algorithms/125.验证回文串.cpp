/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp_s;
        for (char ch: s) {
            if (isalnum(ch)) {    // 判断字符是否为(大小写)字母或数字
                tmp_s += tolower(ch);
            }
        }

        int n = tmp_s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (tmp_s[left] != tmp_s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end

