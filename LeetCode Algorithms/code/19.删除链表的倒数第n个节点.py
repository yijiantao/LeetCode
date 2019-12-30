#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        # 使用前后指针: 前指针先走n步，然后前、后指针同时走，
        # 当前指针走到节点尾时，后指针刚好走到要删除的节点。
        p_head = ListNode(0)
        p_head.next = head    # 左指针

        runner, walker = p_head, p_head
        
        for _ in range((n + 1)):
            runner = runner.next

        while runner != None:
            runner = runner.next
            walker = walker.next
        
        walker.next = walker.next.next
        return p_head.next
# @lc code=end

