/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left_index = 0, right_index = s.size() - 1;
        while (left_index < right_index)
        {
            std::swap(s[left_index++], s[right_index--]);
        }
        // for (auto _v:s) std::cout << _v << ' ';
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution S;
    std::vector<char> s = {'h'};
    S.reverseString(s);
    return 0;
}

