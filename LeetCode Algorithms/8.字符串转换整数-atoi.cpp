/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        string res_str = "";
        for (int _index = 0; _index < str.size(); ++_index) {
            if (res_str.size() ==0 && str[_index] == ' ') continue;
            else if ((str[_index] == '-' || str[_index] == '+') && (_index + 1) < str.size() && int(str[_index + 1]) <= 57 && int(str[_index + 1]) >= 48) res_str += str[_index];
            else if (int(str[_index]) <= 57 && int(str[_index]) >= 48) res_str += str[_index];
            else if (res_str.size() ==0 && (int(str[_index]) > 57 || int(str[_index]) < 48)) return 0;
            else if (res_str.size() !=0 && (int(str[_index]) > 57 || int(str[_index]) < 48)) break;
            else continue;
        }
        if (atof(res_str.c_str()) > INT_MAX) return INT_MAX;
        if (atof(res_str.c_str()) < INT_MIN) return INT_MIN;
        return atoi(res_str.c_str());
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "   -42";
    cout << s.myAtoi(str) << endl;
    return 0;
}
