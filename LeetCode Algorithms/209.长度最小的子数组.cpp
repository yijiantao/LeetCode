/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, temp = 0, i =0;
        for (int j = 0; j < nums.size(); ++j){
            temp += nums[j];
            while (temp>=s) {  //指针i不断前进，temp不断减去nums[i]，直到小于s，则退出循环
                res = min(res, j - i + 1);
                temp -= nums[i++];
            }
        }
        return i == 0 ? 0 : res;
    }
};
// @lc code=end

