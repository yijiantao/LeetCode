/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nums_5 = 0, nums_10 = 0;
        for (auto _v: bills) {
            if (_v == 5) {
                nums_5 += 1;
                continue;
            } else if (_v == 10) {
                if (nums_5 <= 0) return false;
                nums_5 -= 1;
                nums_10 += 1;
            } else if (_v == 20) {
                cout << nums_5 << ' ' << nums_10 << endl;
                if (nums_5 <= 0) return false;
                if (nums_5 * 5 + nums_10 * 10 < 20) return false;
                if (nums_10 >= 1 && nums_5 >= 1) {
                    nums_5 -= 1;
                    nums_10 -= 1;
                }
                if (nums_5 >= 3) {
                    nums_5 -= 3;
                }
            }
        }
        return true;
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    vector<int> bills = {5,5,5,10,5,5,10,20,20,20};
    Solution s;
    cout << s.lemonadeChange(bills) << endl;
    return 0;
}
