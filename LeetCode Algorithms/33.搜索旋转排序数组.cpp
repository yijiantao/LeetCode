/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 题目要求 时间复杂度：O(logn)
        // 选择二分查找
        //二分的写法有很多种，所以在判断 target 大小与有序部分的关系的时候可能会出现细节上的差别。

        int length = nums.size();
        if (length == 0) return -1;
        if (length == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = length -1;

        //区间内递增一定是连续的，递减则不一定
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;    // 恰好相等 
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[length - 1]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

