/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0, flag = 0;
        map<char, int> cout_chr_dict;
        for (char _v: s){
            if (cout_chr_dict.count(_v) == 0) cout_chr_dict[_v] = 0;
            cout_chr_dict[_v] ++;
        }
            
        for (auto p: cout_chr_dict){
            int _v = p.second;
            res += _v / 2 * 2;
            if (_v % 2 == 1 and res % 2 == 0)  //加上一个单字符放在中间
                ++res;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "abccccdd";
    cout <<sol.longestPalindrome(s) << endl;
    return 0;
}
