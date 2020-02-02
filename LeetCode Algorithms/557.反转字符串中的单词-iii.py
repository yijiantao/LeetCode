#
# @lc app=leetcode.cn id=557 lang=python3
#
# [557] 反转字符串中的单词 III
#

# @lc code=start
class Solution:
    @classmethod
    def reverseWords(self, s: str) -> str:
        return ' '.join([_index[::-1] for _index in s.split(' ')])
        
# @lc code=end

print (Solution.reverseWords(s = "Let's take LeetCode contest"))