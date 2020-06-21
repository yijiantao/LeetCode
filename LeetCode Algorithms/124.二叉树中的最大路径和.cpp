/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int val = INT_MIN;
        dfs(root, val);
        return val;
    }
    
    // 返回经过root的单边分支最大和， 即Math.max(root, root+left, root+right)
    int dfs(TreeNode* root, int &val) {
        if (root == nullptr) return 0;
        //计算左边分支最大值，左边分支如果为负数还不如不选择
        int left = std::max(dfs(root->left, val), 0);

        //计算右边分支最大值，右边分支如果为负数还不如不选择
        int right = std::max(dfs(root->right, val), 0);

        //left->root->right 作为路径与历史最大值做比较
        int tmp_val = root->val + left + right;
        val = std::max(val, tmp_val);

        // 返回经过root的单边最大分支给上游
        return root->val + std::max(left, right);
    }
};
// @lc code=end

