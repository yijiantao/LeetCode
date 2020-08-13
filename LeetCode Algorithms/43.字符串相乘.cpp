/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int flag = 0, temp_value = 0;
        int low_length = num1.size() > num2.size() ? num1.size() : num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int _index = 0; _index < low_length; ++_index) {

            if (_index < num1.size() && _index < num2.size()) {
                temp_value = (num1[_index] - '0') * (num2[_index] - '0') + flag;
                flag = temp_value / 9;
                res += to_string((temp_value) % 9);
            } else if (_index >= num1.size() && _index < num2.size()) {
                res += to_string((num2[_index] - '0') + flag);
                flag = 0;
            } else if (_index < num1.size() && _index >= num2.size()) {
                res += to_string((num2[_index] - '0') + flag);
                flag = 0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

