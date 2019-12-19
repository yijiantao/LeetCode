#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 方法一：
        return [int(_index) for _index in str(int(''.join([str(_index) for _index in digits])) + 1)]
        # 方法二:

# @lc code=end
