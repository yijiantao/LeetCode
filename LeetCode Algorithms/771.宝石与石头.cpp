/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> map;
        for (char c : S) map[c] ++;
        int res = 0;
        for (char c : J) res += map[c];
        return res;

    }
};
// @lc code=end

