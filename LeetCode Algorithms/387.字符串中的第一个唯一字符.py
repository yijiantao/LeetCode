#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#

# @lc code=start
import collections
class Solution:
    @classmethod
    def firstUniqChar(self, s: str) -> int:
        # 如果不先统计会导致超时 Time Limit Exceeded
        count_dict = collections.Counter(s)
        for _index, _value in enumerate(s):
            # if (s.count(_value)) == 1: 如果每次都临时统计会导致超时 Time Limit Exceeded
            if (count_dict[_value]) == 1:
                return _index
        return -1
# @lc code=end

print (Solution.firstUniqChar(s = "LeetCode"))