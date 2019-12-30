#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#

# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        judge_circle_set = {1}
        while n not in judge_circle_set:
            judge_circle_set.add(n)
            n = sum(int(_index)**2 for _index in str(n))
        return n == 1
        
# @lc code=end

