class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int _index = 1; _index < nums.size(); ++_index) {
            nums[_index] += nums[_index - 1];
        }
        return nums;
    }
};