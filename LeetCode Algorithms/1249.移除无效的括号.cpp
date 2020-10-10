/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int flag = -1;
        stack<char> insert_char;
        stack<int> insert_num;
        for (int _index = 0; _index < s.size(); ++_index) {
            if (s[_index] == '(') {
                insert_char.push('(');
                insert_num.push(_index);
            } else if (s[_index] == ')') {
                if (!insert_char.empty()) {
                    if (insert_char.top() == '(') {
                        insert_char.pop();
                        insert_num.pop();
                    } else {

                    }
                } else {
                    flag = _index;
                }
            }
            
        }
        return (flag != -1) ? s.erase(flag, 1) : s;
    }
};
// @lc code=end

