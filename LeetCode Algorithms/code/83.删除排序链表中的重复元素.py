#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        list_set = []
        p = ListNode(None)
        p.next = head
        while p.next:
            if p.next.val not in list_set:
                list_set.append(p.next.val)
                p = p.next
            else:
                p.next = p.next.next
        return head
# @lc code=end

