#
# @lc app=leetcode.cn id=389 lang=python3
#
# [389] 找不同
#

# @lc code=start
import collections
class Solution:
    @classmethod
    def findTheDifference(self, s: str, t: str) -> str:
        # 方法一：利用内置函数求解
        # return list(collections.Counter(t) - collections.Counter(s))[0]

        # 方法二：遍历一遍s，对s中的每一个字符，用replace函数在t中找到并删除，返回t
        # replace() 第三个参数代表最大替换次数
        for i in s:
            t = t.replace(i,'',1)
        return t

        # 方法三： 利用ASCLL 做减法
        return chr(sum(map(ord, t)) - sum(map(ord, s)))
# @lc code=end

print (Solution.findTheDifference(s = 'abcd', t = 'abcde'))