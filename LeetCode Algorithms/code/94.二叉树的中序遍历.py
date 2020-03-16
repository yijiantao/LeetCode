#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def helper(node, res):
            if node:
                if node.left: helper(node.left, res)
                res.append(node.val)
                if node.right: helper(node.right, res)

        helper(root, res)
        return res
# @lc code=end

