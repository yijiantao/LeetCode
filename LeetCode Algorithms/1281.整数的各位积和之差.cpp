/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int ji = 1, sum = 0, num  =0;
        if (n < 10) return 0;
        while (n > 0) {
            num = n % 10;
            ji *= num;
            sum += num;
            n /= 10;
        }
        return ji - sum;
    }
};
// @lc code=end

