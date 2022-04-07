#include <iostream>
#include <fstream>  // 处理命名文件的IO
#include <sstream>     //stringstream 完成内存String的IO
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

int main()
{
    std::vector<int> node_val{1,2,3,4};
    ListNode* head = new ListNode();
    ListNode* p = head;
    for (auto _v: node_val) {
        p->val = _v;
        p->next = new ListNode();
        p = p->next;
    }

    Solution s{};
    s.reorderList(head);

    // -*-*-*-*-*- 打印 -*-*-*-*-*-*-*-*-*-*-*-*-*
    p = head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}