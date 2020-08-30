/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string res = "", tmp_s = "";
        if (s.size() <= 1) return s;
        for (auto _c: s) {
            if (_c == ' '){
                reverse(tmp_s.begin(), tmp_s.end());
                res += tmp_s;
                res += ' ';
                tmp_s = "";
            }
            else tmp_s += _c;
        }
        if (tmp_s != "") {
            reverse(tmp_s.begin(), tmp_s.end());
            res += tmp_s;
        }
        return res;
    }
};
// @lc code=end

