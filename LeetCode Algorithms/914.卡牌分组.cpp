/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() == 0) return false;
        int cut[10000] = {0}, g = 0;
        for (auto _v: deck) cut[_v] ++;
        for (int _index =0; _index < 1000; ++_index) if (cut[_index]){
            if (~g) g = gcd(g, cut[_index]);
            else g = cut[_index];
        }
        return g >= 2 ? true : false;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> deck = {1,1,1,2,2,2,3,3};
    cout << s.hasGroupsSizeX(deck) << endl;
    return 0;
}
