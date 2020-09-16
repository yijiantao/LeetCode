/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:

    bool isDiv(int nums) {
        int temp_nums = nums;
        while (nums)
        {
            int div_res = nums % 10;
            if (div_res == 0 || (temp_nums % div_res) != 0) return false;
            nums /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int _v = left; _v <= right; ++_v) {
            if (isDiv(_v)) res.push_back(_v);
        }
        return res;
    }
};
// @lc code=end

