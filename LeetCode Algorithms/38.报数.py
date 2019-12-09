#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 报数
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int, result = '1') -> str:
        # 这个题的题意也是无力吐槽(┳＿┳)... 
        # 熟练掌握 itertools 里的方法
        from itertools import groupby
        result = '1'
        for _index in range(1, n):
            result = ''.join([str(len(list(_gen))) + _val for _val, _gen in groupby(result)])
        return result
        
# @lc code=end

