#include <iostream>
#include <stack>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> stack_node;
        ListNode* p = new ListNode();
        p = head;
        while (p->next) {
            stack_node.push(p);
            p = p->next;
        }

        p = head;
        ListNode* q = stack_node.top();
        stack_node.pop();
        while (p != q) {
            q->next = p->next;
            p->next = q;
            p = q->next->next;
            q = stack_node.top();
            stack_node.pop();
        }
    }
};

int main()
{
    std::vector<int> node_val{1,2,3,4};
    ListNode* head = new ListNode();
    ListNode* p = new ListNode();
    p = head;
    for (auto _v: node_val) {
        p->val = _v;
        p->next = new ListNode();
        p = p->next;
    }

    Solution s{};
    s.reorderList(head);

    // -*-*-*-*-*- 打印 -*-*-*-*-*-*-*-*-*-*-*-*-*
    p = head;
    while (p->next) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}