/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	link_list := ListNode{}
	tail := &link_list
	
	for l1 != nil || l2 != nil {
		if l1 == nil {
			tail.Next = l2
			break
		}

		if l2 == nil {
			tail.Next = l1
			break
		}

		if l1.Val > l2.Val {
			tail.Next = l2
			l2 = l2.Next
		} else {
			tail.Next = l1
			l1 = l1.Next
		}

		tail = tail.Next
	}

	return link_list.Next
}
// @lc code=end

