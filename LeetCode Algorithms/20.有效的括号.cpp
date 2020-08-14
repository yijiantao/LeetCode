/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (auto _c: s) {
            if (_c == '(' || _c == '{' || _c == '[') res.push(_c);
            else {
                if (_c == ')' && res.size() >= 1 && res.top() == '(') res.pop();
                else if (_c == ']' && res.size() >= 1 && res.top() == '[') res.pop();
                else if (_c == '}' && res.size() >= 1 && res.top() == '{') res.pop();
                else return false;
            }
        }
        return res.empty();
    }
};
// @lc code=end

