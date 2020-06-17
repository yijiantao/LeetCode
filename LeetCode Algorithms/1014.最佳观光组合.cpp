/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        int pre_max = A[0] + 0; // 初始值
        for (int j = 1; j < A.size(); ++j) {
            res = max(res, pre_max + A[j] - j);  //判断能否刷新res
            pre_max = max(pre_max, A[j] + j);    // 判断能否刷新pre_max， 得到更大的A[i] + i
        }

        return res;
    }
};
// @lc code=end

