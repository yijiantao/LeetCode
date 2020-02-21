#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层次遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    @classmethod
    def levelOrder(self, root):
        res = []
        if not root: return res
        def dfs(node, level):

            # 如果当前为新的一层开始遍历，则创建 []
            if len(res) == level:
                res.append([])

            # 将当前节点的值添加到 res[level] list中
            res[level].append(node.val)

            # 有子节点，则继续向下遍历
            if node.left:
                dfs(node.left, level + 1)
            if node.right:
                dfs(node.right, level + 1)
        dfs(root, 0)
        return res

# @lc code=end

print (Solution.levelOrder(root=[3,9,20,None,None,15,7]))