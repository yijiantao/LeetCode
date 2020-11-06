/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }

    static bool cmp(int a, int b) {
        int bca = bitCount(a), bcb = bitCount(b);
        return (bca == bcb) ? a < b : bca < bcb;
    }

    static int bitCount(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1) cnt ++;
            n >>= 1;
        }
        return cnt;
    }
};
// @lc code=end

