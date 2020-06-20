/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s.data(), p.data());
    }
    bool match(char* s, char* p) {
        if (!*p) return !*s;
        if (*(p + 1) != '*')
            return true;
    }
};
// @lc code=end

