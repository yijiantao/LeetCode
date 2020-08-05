/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for (int _index =0; _index < s.size(); ++_index)
            if ((_index == 0 || s[_index - 1] == ' ') && s[_index] != ' ')
                res ++;
        return res;
    }
};
// @lc code=end

