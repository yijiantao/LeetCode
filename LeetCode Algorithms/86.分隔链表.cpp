/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_list = new ListNode(0);
        ListNode* big_list = new ListNode(0);
        ListNode* small_head = small_list;
        ListNode* big_head = big_list;

        while (head != nullptr){
            if (head->val >= x){
                big_list->next = head;
                big_list = big_list->next;
            }else{
                small_list->next = head;
                small_list = small_list->next;
            }
            head = head->next;
        }
        big_list->next = nullptr;
        small_list->next = big_head->next;

        return small_head->next;

    }
};
// @lc code=end

