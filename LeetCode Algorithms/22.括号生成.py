#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#

# @lc code=start
class Solution:
    # def generateParenthesis(self, n: int) -> List[str]:
    @classmethod
    def generateParenthesis(self, n):
        # 回溯法 
        res = []
        def backtrack(S = '', left = 0, right = 0):
            print (S)
            if len(S) == 2 * n:
                res.append(S)
                return
            if left < n:
                backtrack(S+'(', left + 1, right)
            if right < left:    # 如果不超过左括号的数量，就可以放一个右括号。
                backtrack(S+')', left, right + 1)
        backtrack()
        return res
# @lc code=end

print (Solution.generateParenthesis(n = 3))