/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        auto max_value = std::max_element(candies.begin(), candies.end());
        for (auto _v : candies) {
            if (_v + extraCandies >= *max_value) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
// @lc code=end

