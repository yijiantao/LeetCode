/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int _i = 1; _i < strs.size(); ++_i) {
            if (res.size() == 0 || strs[_i].size() == 0) return "";
            string tmp_res = "";
            int _index = 0;
            while (res[_index] != '\0' || strs[_i][_index] != '\0'){
                if (res[_index] == strs[_i][_index]) {
                    tmp_res.push_back(res[_index]);
                    _index ++;
                }
                else break;
            }
            res = tmp_res;
        }
        return res;
    }
};
// @lc code=end

