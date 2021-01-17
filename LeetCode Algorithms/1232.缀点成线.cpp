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
        for (int _index = 1; _index + 1 < coordinates.size(); ++_index) {
            if ((coordinates[_index][0] - coordinates[_index - 1][0]) * (coordinates[_index+1][1] - coordinates[_index][1]) !=
               (coordinates[_index][1] - coordinates[_index-1][1]) * (coordinates[_index +1][0] - coordinates[_index][0]))
               return false;
        }
        return true;
    }
};
// @lc code=end

