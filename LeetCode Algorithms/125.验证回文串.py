#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#

# @lc code=start
class Solution:
    # def isPalindrome(self, s: str) -> bool:
    @classmethod
    def isPalindrome(self, s):
        # filter_str = lambda x: str.lower(''.join(filter(str.isalnum, str(x).replace(' ', ''))))
        # return filter_str(s) == ''.join(reversed(filter_str(s)))

        
# @lc code=end

print (Solution.isPalindrome(s = "1A man, a plan, a canal: Panama1"))