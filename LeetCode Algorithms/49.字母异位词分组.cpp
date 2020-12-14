/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> hash_map;
        int tag = 1;
        string temp;
        for (string& str: strs) {
            temp = str;
            sort(str.begin(), str.end());
            if (hash_map[str] == 0) {
                hash_map[str] = tag++;
                res.push_back({temp});
            } else {
                res[hash_map[str] - 1].push_back(temp);
            }
        }
        return res;
    }
};
// @lc code=end

