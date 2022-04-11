/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), times = n / 3;
        vector<int> res;
        if (n < 1) return res;

        map<int, int> _maps;
        map<int, int>::iterator iter;
        for (int _idx = 0; _idx < n; ++_idx) {
            if (_maps.end() != _maps.find(nums[_idx])) {
                _maps.insert(pair<int, int>(nums[_idx], 0));
            }
            _maps[nums[_idx]] ++;
        }

        for (iter = _maps.begin(); iter != _maps.end(); ++iter) {
            if (iter->second > times) res.push_back(iter->first);
        }

        return res;
    }
};
// @lc code=end

