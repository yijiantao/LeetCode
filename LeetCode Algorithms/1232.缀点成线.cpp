/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 3) return true;
        int k = (coordinates[1][1] - coordinates[1][0]) / (coordinates[0][1] - coordinates[0][0]);;
        for (int _index = 2; _index < coordinates.size(); ++_index) {
            int tmp_k = (coordinates[_index][1] - coordinates[_index][0]) / (coordinates[_index-1][1] - coordinates[_index-1][0]);
            if (k == tmp_k) k = tmp_k;
            else return false;
        }
        return true;
    }
};
// @lc code=end

