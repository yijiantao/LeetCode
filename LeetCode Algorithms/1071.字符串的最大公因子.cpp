/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<algorithm>

class Solution {

    bool judge(string temp, string str_all){
        string res = "";
        for (int _index = 0; _index < (int)str_all.size() / temp.size(); ++_index){
            res += temp;
        }
        return res == str_all;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len_1 = str1.size(), len_2 = str2.size();
        string res = str1.substr(0, __gcd(len_1, len_2));
        return (judge(res, str1) && judge(res, str2)) ? res : "";
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    string str1 = str1 = "LEET", str2 = "CODE";
    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}
