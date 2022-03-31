/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        std::vector<ListNode*> vector_node;
        ListNode* p = head;
        while (p) {
            vector_node.push_back(p);
            p = p->next;
        }

        p = head;
        int i = 0, j = vector_node.size() - 1;
        while (i < j)
        {
            vector_node[i]->next = vector_node[j];
            ++i;
            if (i == j) break;
            vector_node[j]->next = vector_node[i];
            --j;
        }
        vector_node[i]->next = nullptr;
    }
};
// @lc code=end

