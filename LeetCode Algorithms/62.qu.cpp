#include<bits/stdc++.h>
// #include"output_container.h"
using namespace std;
/*
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

 

示例 1：

输入: n = 5, m = 3
输出: 3
示例 2：

输入: n = 10, m = 17
输出: 2
 

限制：

1 <= n <= 10^5
1 <= m <= 10^6
*/
class Solution {
public:
    int lastRemaining(int n, int m) {
        int result = 0;
        for (int i = 2; i <= n; ++i) {
            result = (result + m) % i;
        }
        return result;
        // if (n == 0) return 0;
        // vector<int> a;
        // for (int _index = 0; _index < n; ++_index) a.push_back(_index);
        
        // int _count = 0;
        // while (a.size() != 1)
        // {
        //     for (int _index = 0; _index < a.size(); ++_index) {
        //         ++_count;
        //         if (_count == m) {
        //             for (int _v: a) cout << _v << ' ';
        //             cout <<  _index << endl;
        //             a.erase(a.begin() + _index);
        //             _count = 0;
        //         }
        //     }
            
        // }
        // return a.at(0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 10, m = 17;
    cout << s.lastRemaining(n, m) << endl;
    return 0;
}
