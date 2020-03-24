#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int not_choose = 0, choose = 0;   // 表示当前的预约 “不接受/接受”
        for (int _index = 0; _index < nums.size(); ++_index){
            int temp = not_choose;
            not_choose = max(not_choose, choose);
            choose = max(choose, temp + nums[_index]);
            
        }
        cout << not_choose << '\t' << choose << endl;
        return max(not_choose, choose);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.massage(nums) << endl;
    return 0;
}
