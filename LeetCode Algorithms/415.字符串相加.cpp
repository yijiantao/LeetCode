/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
         int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result;
        bool flag = 0;

        while (i >= 0 && j >= 0) {
            int sum = num1[i--] - '0' + num2[j--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        while (i >= 0) {
            int sum = num1[i--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        while (j >= 0) {
            int sum = num2[j--] - '0' + flag;
            flag = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        if (flag == 1) { result.push_back('1'); }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end

