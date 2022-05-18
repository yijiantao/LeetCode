/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *quick = head->next, *slow = head;
        while (slow != quick) {
            if (quick == nullptr || quick->next == nullptr) return false;
            quick = quick->next->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

