#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        if (S == "") return S;
        int count_str = 1;
        string temp_S = "";
        temp_S += S[0];
        for (int _index = 1; _index != S.size(); ++_index){
            if (temp_S[temp_S.size() - 1] != S[_index]){
                temp_S += to_string(count_str);
                temp_S += S[_index];
                count_str = 1;
            }
            else {
                count_str += 1;
            }
        }
        temp_S += to_string(count_str);
        return S.size() <= temp_S.size() ? S : temp_S;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abbccd";
    cout << s.compressString(str) << endl;
    return 0;
}
