/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;
        sort(A.begin(), A.end());
        int right = A.size() - 1;
        while (right >= 2) {
            if (A[right-2] + A[right-1] > A[right]) {
                return A[right-2]+A[right-1]+A[right];
            }
            right --;
        }
        return 0;
    }
};
// @lc code=end

