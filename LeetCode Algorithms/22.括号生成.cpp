/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> res;
    void backtrack(string temp_str, int left, int right, int n) {
        if (temp_str.size() == 2 * n) {
            res.push_back(temp_str);
            return ;
        }
        if (left < n) backtrack(temp_str + "(", left + 1, right, n);
        if (right < left) backtrack(temp_str + ")", left, right + 1, n);    // 如果不超过左括号的数量，就可以放一个右括号。
    }
    vector<string> generateParenthesis(int n) {
        string temp_str = "";
        int left = 0, right = 0;
        backtrack(temp_str, left, right, n);
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 3;
    s.generateParenthesis(n);
    return 0;
}
