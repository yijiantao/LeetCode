/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include<bits/stdc++.h>
#include"coutStackQueue.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() ==0) return 0;
        int res =0;
        stack<int> stack_dec;    // 单调栈
        for (int _index = 0; _index < height.size(); ++_index) {
            while (!stack_dec.empty() && height[stack_dec.top()] < height[_index]) {
                int curIdx = stack_dec.top();
                // 如果栈顶元素一直相等，那么全部都 pop 出去，只留第一个。
                while (!stack_dec.empty() && height[stack_dec.top()] == height[curIdx]) stack_dec.pop();
                if (!stack_dec.empty()) {
                    int stackTop = stack_dec.top();
                    // stackTop此时指向的是此次接住的雨水的左边界的位置。右边界是当前的柱体，即_index。
                    // Math.min(height[stackTop], height[_index]) 是左右柱子高度的min，减去height[curIdx]就是雨水的高度。
                    // _index - stackTop - 1 是雨水的宽度。
                    res += (min(height[stackTop], height[_index]) - height[curIdx]) * (_index - stackTop - 1);
                }
            }
            stack_dec.push(_index);
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
