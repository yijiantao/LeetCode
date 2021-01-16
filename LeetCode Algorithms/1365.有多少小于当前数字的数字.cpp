/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for (int _i = 0; _i < nums.size(); ++_i) {
            int tmp_count = 0;
            for (int _j =0; _j < nums.size(); ++_j){
                if (_i != _j and nums[_i] > nums[_j])
                tmp_count +=1; 
            }
            res.push_back(tmp_count);
        }
        return res;
    }
};
// @lc code=end

