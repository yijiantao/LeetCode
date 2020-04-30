/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 * 
 */

// @lc code=start
class Solution {
public:
    int squareSum(int m) {
        int sum = 0;
        while (m > 0) {
            int temp_num = m % 10;
            sum += (temp_num * temp_num);
            m /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {

        set<int> seen = {};
        while (n != 1 && seen.find(n) == seen.end()) {   // set find函数 没查找到 即 == set.end()
            seen.insert(n);
            n = squareSum(n);
        }
        return n == 1;
    }
};
// @lc code=end

