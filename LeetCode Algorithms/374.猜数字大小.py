#
# @lc app=leetcode.cn id=374 lang=python3
#
# [374] 猜数字大小
#

# @lc code=start
# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:


class Solution:
    @classmethod
    def guessNumber(self, n: int) -> int:
       
        res = self().binary_search(0, n)
        return res

    def binary_search(self, left, right):
        mid = int((left + right) / 2)
        
        test_res = guess(mid)

        if test_res == 0:
            return mid
        elif test_res > 0:
            return self.binary_search(mid + 1, right)    # 如果搞反了，很容易在mid处边界，陷入无限循环
        else:
            return self.binary_search(left, mid - 1)

# @lc code=end

print(Solution.guessNumber(n=10))
