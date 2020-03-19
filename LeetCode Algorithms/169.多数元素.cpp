/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */

// @lc code=start
#include<bits/stdc++.h>
// #include<map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nums_length = nums.size(), max_count = INT_MIN, res;
        int half_nums_length = (int)nums_length / 2;
        map<int, int> count_nums_dict;
        for (int _value: nums){
            if (count_nums_dict.count(_value) == 0) count_nums_dict[_value] = 0;
            count_nums_dict[_value] += 1;
        }
        // for (auto p: count_nums_dict)
        //    int _v = p.second;
        for (map<int, int>::iterator iter=count_nums_dict.begin(); iter != count_nums_dict.end(); iter++){
            if (iter->second > max_count){
                res = iter->first;
                max_count = iter->second;
            }
        }
        return res;
    }
};
// @lc code=end

