#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s == "") return "";
        string res ="", tmp_s = "";
        stack<string> s_stack;
        for (char _s:s) {
            if (_s == ' ') {
                if (tmp_s != "") s_stack.push(tmp_s);
                tmp_s = "";
                continue;
            }
            tmp_s += _s;
        }
        if (tmp_s != "") s_stack.push(tmp_s);
        while (!s_stack.empty())
        {
            res += s_stack.top();
            s_stack.pop();
            if (s_stack.empty()) break;
            res += " ";
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string temp_s = "     ";
    cout << s.reverseWords(temp_s) << endl;
    return 0;
}
