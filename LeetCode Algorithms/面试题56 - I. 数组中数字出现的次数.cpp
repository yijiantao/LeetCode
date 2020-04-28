#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int, int> total_dict;
        for (auto _v: nums) total_dict[_v] ++;
        for (auto _v: total_dict) {
            if (_v.second == 1) ans.emplace_back(_v.first);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {};
    s.singleNumbers(nums);
    return 0;
}
