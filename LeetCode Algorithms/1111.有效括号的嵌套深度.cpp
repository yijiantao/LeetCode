/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        if (seq == "") return {0};
        vector<int> res;
        int flag = 0;
        for (auto _s: seq) {
            if (_s == '(') {
                flag ++;
                res.push_back(flag % 2);
            }
            if (_s == ')') {
                res.push_back(flag % 2);
                flag --;
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string seq = "((()))";
    for (auto _s: s.maxDepthAfterSplit(seq)) cout << _s << endl;
    return 0;
}
