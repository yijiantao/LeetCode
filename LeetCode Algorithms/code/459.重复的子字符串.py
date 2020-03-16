#
# @lc app=leetcode.cn id=459 lang=python3
#
# [459] 重复的子字符串
#

# @lc code=start
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        #遍历长度for _index in range(1 ~ len(s)/2+1)的所有子字符串（从index=0开始取），
        # 所取的子字符串 s[:_index] 乘以切片数len(s)//i,得到的字符串若和原字符串相等，则返回True

        n = len(s)
        for _index in range(1, n // 2 + 1):
            if n % _index == 0 and s[:_index] * (n // _index) == s:
                return True
        return False
        
# @lc code=end

