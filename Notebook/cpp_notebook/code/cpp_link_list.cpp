#include<bits/stdc++.h>
using namespace std;

/**
 * 头插法、尾插法;
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    ListNode* endCreatLink(vector<int> &nums) {
        /* 尾插法 */
        ListNode *res_link, *head;
        res_link = head = new ListNode(0);
        head -> next = res_link;

        for (auto _v: nums) {
            // cout << _v << " " << typeid(_v).name() << endl;
            auto curnode = new ListNode(_v);
            head -> next = curnode;
            head = head -> next;
        }
        return res_link->next;
    }

    ListNode* headCreatLink(vector<int> &nums) {
        /* 头插法 */
        
        ListNode* res_link = nullptr;
        for (auto _v: nums) {
            auto curnode = new ListNode(_v);
            curnode -> next = res_link;
            res_link = curnode;
        }
        return res_link;
    }

    void printfLinkList(ListNode* head) {
        ListNode* ptr_head = head;
        while (ptr_head) {
            cout << ptr_head->val << " ";
            ptr_head = ptr_head->next;
        }
        return ;
    }
};

int main(int argc, char const *argv[])
{
    /* int <---> char <---> string 互转
    // string to int && int to string
    int n = 123;
    char *char_n = "abcd";
    char char_n_2[] = "abcd";

    string string_n = to_string(n);
    int int_s = stoi(string_n);

    int int_s_2 = atoi(char_n_2);
    cout << int_s << " " << typeid(int_s).name() << endl;
    cout << int_s_2 << " " << typeid(int_s_2).name() << endl;
    */

    //  链表 插入操作
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "待插入链表数据：";
    for (auto _v: nums)  cout << _v << endl;

    Solution s;
    cout << "头插法：";
    s.printfLinkList(s.headCreatLink(nums));

    cout << "尾插法：";
    s.printfLinkList(s.endCreatLink(nums));
    return 0;
}
