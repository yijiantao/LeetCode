#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result_link = ListNode(0)
        p_link = result_link
        flag_sum = 0 # 上次相加是否需要进位加1的标志

        while l1 and l2:
            p_link.next = ListNode((l1.val + l2.val + flag_sum) % 10)
            flag_sum = (l1.val + l2.val + flag_sum) // 10
            p_link, l1, l2, = p_link.next, l1.next, l2.next

        l1 = l1 if l1 else l2
        while flag_sum:
            if l1:
                p_link.next = ListNode((l1.val + flag_sum) % 10)
                flag_sum = (l1.val + flag_sum) // 10
                p_link, l1 = p_link.next, l1.next
            else:
                p_link.next = ListNode(flag_sum)
                p_link = p_link.next
                break
        p_link.next = l1

        return result_link.next
# @lc code=end

