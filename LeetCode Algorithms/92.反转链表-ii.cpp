/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) return head;
        stack<int> _node_val_stack;
        ListNode* _p = head;
        ListNode* _q = head;
        int _q_idx = 1;
        while (_q != nullptr){
            if (_q_idx == left) _p = _q;
            if (_q_idx >= left) _node_val_stack.push(_q->val);
            if (_q_idx>=right) break;

            _q = _q->next;
            _q_idx ++;
        }

        while (!_node_val_stack.empty()){
            _p->val = _node_val_stack.top();
            _node_val_stack.pop();
            _p = _p->next;
        }
        return head;
    }
};
// @lc code=end

