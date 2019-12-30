#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个排序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # 遍历所有链表，将所有节点的值放到一个数组中。
        self.node = []
        head = point = ListNode(0)
        for link_index in lists:
            while link_index:
                self.node.append(link_index.val)
                link_index = link_index.next
        for node_index in sorted(self.node):
            point.next = ListNode(node_index)
            point = point.next
        return head.next

# @lc code=end

