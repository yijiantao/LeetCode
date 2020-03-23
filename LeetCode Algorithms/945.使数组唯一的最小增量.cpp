/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {  // 0 <= A[i] < 40000
        int ans = 0;
        if (A.size() == 0) return ans;
        sort(A.begin(), A.end());
        // for (int _v: A) cout << _v << endl;
        for (int _index = 1, temp_value = A[0]; _index < A.size(); ++_index){
            if (temp_value < A[_index]){
                temp_value = A[_index];
            }
            else {
                int temp_ans = temp_value - A[_index] + 1;
                ans += temp_ans;
                temp_value = A[_index] + temp_ans;
            }

        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {1,2,2};
    cout << s.minIncrementForUnique(A);
    return 0;
}
