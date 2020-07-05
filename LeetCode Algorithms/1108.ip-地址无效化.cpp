/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for (auto _c: address) {
            if (_c == '.') res += "[.]";    // string += 往字符串后追加和python一样，，，
            else res += _c;
        }
        return res;
    }
};
// @lc code=end

