/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        // 方法一：STL 求交函数
        // set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(res, res.begin()));

        // 方法二： 双指针

        
        return res;
    }
};
// @lc code=end

