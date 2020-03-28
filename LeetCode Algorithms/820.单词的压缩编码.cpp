/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> words_set(words.begin(), words.end());
        int res = 0;
        for (auto word: words)
            for (int _index = 1; _index < word.size(); ++_index){
                cout << word << ' ';
                /*
                    erase方法原型
                        1. basic_string & erase(size_type pos=0, size_type n=npos);
                        即从给定起始位置pos处开始删除, 要删除字符的长度为n, 返回值修改后的string对象引用
                    C++中erase函数的使用,可以用来删除内存擦除
                        erase函数的原型如下：
                        （1）string& erase ( size_t pos = 0, size_t n = npos );
                        （2）iterator erase ( iterator position );
                        （3）iterator erase ( iterator first, iterator last );
                        也就是说有三种用法：
                        （1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
                        （2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
                        （3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）

                    如果想删除 set 容器存储的元素，可以选择用 erase() 或者 clear() 成员方法。
                        set 类模板中，erase() 方法有 3 种语法格式，分别如下：
                        //删除 set 容器中值为 val 的元素
                        size_type erase (const value_type& val);
                        //删除 position 迭代器指向的元素
                        iterator  erase (const_iterator position);
                        //删除 [first,last) 区间内的所有元素
                        iterator  erase (const_iterator first, const_iterator last);
                */
                cout << "substr  " << word.substr(_index) << endl;
                words_set.erase(word.substr(_index));
            }
        for (auto word: words_set){
            // cout << word << endl;
            res += (word.size() + 1);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words = {"time", "me", "bell"};
    cout << s.minimumLengthEncoding(words) << endl;
    return 0;
}
