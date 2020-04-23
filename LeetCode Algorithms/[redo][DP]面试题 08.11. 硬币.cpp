#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode-cn.com/problems/coin-lcci/solution/ying-bi-by-leetcode-solution/
*/
class Solution {
    private:
        int mod = 1000000007;
        int coins[4] = {25, 10, 5, 1};

    public:
        int waysToChange(int n) {
            vector<int> f(n + 1);
            f[0] = 1;
            for (int c = 0; c < 4; ++c) {
                int coin = coins[c];
                for (int i = coin; i <= n; ++i) {
                    f[i] = (f[i] + f[i - coin]) % mod;
                }
            }
            return f[n];
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 5;
    cout << s.waysToChange(n) << endl;
    return 0;
}
