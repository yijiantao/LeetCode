/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        vector<short> v(26);
        for (auto c:s) v[c - 'a']++;

        string ans(s);
        int index = 0;
        
        while (s.size() > index)
        {
            for (int i = 0; i < 26; ++i) if (v[i] > 0 && v[i]--) ans[index++] = 'a' + i;
            for (int i = 25; ~i; --i) if (v[i] > 0 && v[i]--) ans[index++] = 'a' + i;
        }
        return ans;
    }
};
// @lc code=end

