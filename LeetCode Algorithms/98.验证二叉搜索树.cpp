/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long pre = LONG_MIN;    // 保存前一个变量的值！！！ 机智！！
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        // 中序遍历
        // 访问左子树
        if (!isValidBST(root->left)) return false;
         // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        // 访问右子树
        return isValidBST(root->right);
    }
};
// @lc code=end

