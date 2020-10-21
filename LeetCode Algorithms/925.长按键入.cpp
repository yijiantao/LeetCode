/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if(name[i]==typed[j]) i++, j++;
            else if(j>0 && typed[j-1]==typed[j]) j++;//长压的情况
            else return false;
        }
        while(j>0&&j<typed.size()&&typed[j]==typed[j-1]) j++;//去除尾部的长压
        if(i==name.size()&&j==typed.size()) return true;
        else return false;
    }
};
// @lc code=end

