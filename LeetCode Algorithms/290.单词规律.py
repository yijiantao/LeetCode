#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#

# @lc code=start
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        # 使用map()函数返回一个迭代器
        # map(function, iterable, ...)根据提供的函数对指定序列做映射或操作。
        # 第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。
        no_emp_str = str.split()
        return list(map(pattern.index, pattern)) == list(map(no_emp_str.index, no_emp_str))

        
# @lc code=end
