#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        """
            利用 栈来存储交换的链表节点
        """
        dummy = ListNode(0)
        p = dummy
        while True:
            count = k
            stack = []
            tmp = head
            while count and tmp:
                print (tmp)
                stack.append(tmp)
                tmp = tmp.next
                count -= 1

            # 当上述循环结束时，tmp指向 k+1的位置
            # 说明剩下的链表不够 k 个，跳出循环
            if count:
                p.next = head
                break

            # 出栈，执行翻转操作
            while stack:
                p.next = stack.pop()
                p = p.next
        
            # 与剩下的链表接起来
            p.next = tmp
            head = tmp

        return dummy.next

# @lc code=end

