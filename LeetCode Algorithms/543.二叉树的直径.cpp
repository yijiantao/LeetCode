/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    int res;
    int dfs(TreeNode* node){
        if (node == NULL) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        res = max(res, L+R+1);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        dfs(root);
        return res - 1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    co
    return 0;
}
