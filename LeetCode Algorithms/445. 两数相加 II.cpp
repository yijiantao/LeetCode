#include<bits/stdc++.h>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s_1, s_2;
        ListNode* res_link = nullptr;
        while (l1) {
            s_1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s_2.push(l2->val);
            l2 = l2->next;
        }
        int mark_flag = 0;
        for (!s_1.empty() or !s_2.empty() or mark_flag != 0) {
            int s_1_v = s_1.empty() ? 0 : s_1.top();
            if (!s_1.empty()) s_1.pop();

            int s_2_v = s_2.empty() ? 0 : s_2.top();
            if (!s_2.empty()) s_2.pop();
            int cur_value = s_1_v + s_2_v + mark_flag;
            mark_flag = cur_value / 10;
            cur_value %= 10;
            auto curnode = new ListNode(cur_value);
            curnode -> next = res_link;
            res_link = curnode;
        }
        return res_link;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.addTwoNumbers();

    return 0;
}
