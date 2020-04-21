/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 * https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/c-onjian-dan-jie-fa-by-yizhe-shi/
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (auto _v: nums) {
            odd += _v & 1;
            ans += odd >= k ? cnt[odd - k] : 0;    // odd 每一个值 只与前一个值有关，
            cnt[odd] += 1;
        }
        for (auto _v: cnt) cout << _v << " ";
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    int a = 1, b = 2;
    cout << (a & 1) << " " << (b & 1) << endl;
    return 0;
}
