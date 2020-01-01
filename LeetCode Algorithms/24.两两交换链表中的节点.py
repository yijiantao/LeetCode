#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        p = ListNode(None)
        p.next = head
        while p.next and p.next.next:
            p.next.val, p.next.next.val = p.next.next.val, p.next.val
            p = p.next.next
        return head
# @lc code=end

