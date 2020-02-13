#
# @lc app=leetcode.cn id=367 lang=python3
#
# [367] 有效的完全平方数
#

# @lc code=start
class Solution:
    @classmethod
    def isPerfectSquare(self, num: int) -> bool:
        if num < 2: return True
        left_index, right_index = 2, num / 2
        while left_index <= right_index:
            _index = int((left_index + right_index) / 2)
            if num == _index ** 2: return True
            if num > _index ** 2:
                left_index = _index + 1
            else:
                right_index = _index - 1
        return False
# @lc code=end

print (Solution.isPerfectSquare(num = 9))