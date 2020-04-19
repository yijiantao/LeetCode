/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // https://leetcode-cn.com/problems/count-the-repetitions/solution/tong-ji-zhong-fu-ge-shu-by-leetcode-solution/
        int res = 0;
        if (!n1 || !n2) return res;
        int s1cnt = 0, index =0, s2cnt = 0;
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index ++;
                    if (index == s2.size()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }

            if (s1cnt == n1) {
                return s2cnt / n2;
            }

            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
                pre_loop = {s1cnt_prime, s2cnt_prime};

                // 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            }
            else {
                recall[index] = {s1cnt, s2cnt};
            }
        }

        // ans 存储的是 S1 包含的 s2 的数量，考虑的之前的 pre_loop 和 in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 的末尾还剩下一些 s1，我们暴力进行匹配
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (char ch: s1) {
                if (ch == s2[index]) {
                    ++index;
                    if (index == s2.size()) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }
        // S1 包含 ans 个 s2，那么就包含 ans / n2 个 S2
        return ans / n2;

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n1 = 4, n2 = 2;
    string s1 ="acb", s2 = "ab";
    cout << s.getMaxRepetitions(s1, n1, s2, n2) << endl;
    return 0;
}
