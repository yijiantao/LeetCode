/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        return false;
    }
};
// @lc code=end

