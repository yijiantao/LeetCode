/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int link_length = 0;
        vector<int> node_val_list = {};
        ListNode* p = head;

        while (p != NULL){
            link_length ++;
            node_val_list.push_back(p->val);
            p = p->next;
        }
        int mid_link_length = link_length / 2;
        for (int _index = 0; _index < mid_link_length; ++_index)
            head = head->next;
        return head;
    }
};
// @lc code=end

