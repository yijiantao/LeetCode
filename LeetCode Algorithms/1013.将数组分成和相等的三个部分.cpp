/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

#include<iostream>
using namespace std;
#include<vector>
// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, target = 0, subSum = 0;
        for (int _value: A) sum += _value;
        if (sum % 3 != 0) return false;
        for (int _index = 0; _index < A.size(); ++_index){
            subSum += A[_index];
            if(subSum == sum / 3){
                target += 1;
                subSum = 0;
            }
            if(target == 3) return true;
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {3,3,6,5,-2,2,5,1,-9,4};
    bool res = s.canThreePartsEqualSum(A);
    cout<<res;
    return 0;
}
