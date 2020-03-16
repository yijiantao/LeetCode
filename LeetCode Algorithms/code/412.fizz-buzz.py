#
# @lc app=leetcode.cn id=412 lang=python3
#
# [412] Fizz Buzz
#

# @lc code=start
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        _value = 1
        res = []
        while _value <= n:
            if _value % 3 == 0 and _value % 5 == 0:
                res.append('FizzBuzz')
            elif _value % 3 == 0:
                res.append('Fizz')
            elif _value % 5 == 0:
                res.append('Buzz')
            else:
                res.append(str(_value))
            _value += 1
        return res
# @lc code=end

