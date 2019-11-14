#
# @lc app=leetcode.cn id=796 lang=python3
#
# [796] 旋转字符串
#

# @lc code=start
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if A == B: return True
        if len(A) == len(B):
            for _index in range(len(B)):
                seq_B_1 = B[:_index]
                seq_B_2 = B[_index:]
                if seq_B_1 in A and seq_B_2 in A:
                    return True
        return False
# @lc code=end

