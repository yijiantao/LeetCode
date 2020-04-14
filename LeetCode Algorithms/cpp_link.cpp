#include<bits/stdc++.h>
using namespace std;

/**
 * 头插法、尾插法;
*/


class Solution {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    ListNode* endCreatLink(ListNode* l1, ListNode* l2) {
        /* 尾插法 */
        string s_1 = "", s_2 = "";
        ListNode *res_link, *head;
        res_link = head = new ListNode(0);
        head -> next = res_link;
        while (l1) {
            s_1 += to_string(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s_2 += to_string(l2->val);
            l2 = l2->next;
        }
        int res_num = stoi(s_1) + stoi(s_2);
        for (auto _v: to_string(res_num)) {
            // cout << _v << " " << typeid(_v).name() << endl;
            auto curnode = new ListNode(_v - '0');
            head -> next = curnode;
            head = head -> next;
        }
        return res_link->next;
    }

    ListNode* headCreatLink(ListNode* l1, ListNode* l2) {
        /* 头插法 */
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
        while (!s_1.empty() or !s_2.empty() or mark_flag != 0) {
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
    /* code */
    return 0;
}
