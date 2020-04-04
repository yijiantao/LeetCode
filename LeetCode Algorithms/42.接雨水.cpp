/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int getMax(vector<int>& height) {
        int max_value = INT_MIN;
        for (auto _v: height) 
            if (_v > max_value) max_value = _v;
        return max_value;
    }
    int trap(vector<int>& height) {
        if (height.size() ==0) return 0;
        int res =0;
        int max_value = getMax(height);
        for (int _index =1; _index <= max_value; ++_index) {
            int temp_res = 0, flag = 0;
            for (int _i = 0; _i < height.size(); ++_i) {
                if (flag && height[_i] < _index) {
                    temp_res ++;
                }
                if (height[_i] >= _index) {
                    res += temp_res;
                    temp_res = 0;
                    flag = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}
