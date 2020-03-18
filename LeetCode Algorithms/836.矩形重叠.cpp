/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /*
            解题思路，如果我们在平面中放置一个固定的矩形 rec2，
            那么矩形 rec1 必须要出现在 rec2 的「四周」，也就是说，矩形 rec1 需要满足以下四种情况中的至少一种：
            - 矩形 rec1 在矩形 rec2 的左侧；
            - 矩形 rec1 在矩形 rec2 的右侧；
            - 矩形 rec1 在矩形 rec2 的上方；
            - 矩形 rec1 在矩形 rec2 的下方。
        */

        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
};
// @lc code=end

