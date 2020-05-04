/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // 贪心法 进行数组正向查找
        // https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/

        int maxPos =0, n = nums.size(), end = 0, step = 0;
        for (int _index = 0; _index < n - 1; ++_index) {
            if (maxPos >= _index) {
                maxPos = max(maxPos, _index + nums[_index]);
                if (_index == end) {
                    end  = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
// @lc code=end

