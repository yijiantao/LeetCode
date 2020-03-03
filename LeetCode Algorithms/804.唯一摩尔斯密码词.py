#
# @lc app=leetcode.cn id=804 lang=python3
#
# [804] 唯一摩尔斯密码词
#

# @lc code=start
class Solution:
    @classmethod
    def uniqueMorseRepresentations(self, words):
        Mores_list = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        return len(set(''.join([Mores_list[ord(_index) - ord('a')] for _index in word]) for word in words))
# @lc code=end

print (Solution.uniqueMorseRepresentations(words= ["gin", "zen", "gig", "msg"]))