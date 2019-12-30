#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 滑动窗口left cur_len
        if not s: return 0
        left = 0
        lookup = set()
        n = len(s)

        max_len = 0
        cur_len = 0

        for _index in range(n):
            cur_len += 1
            while s[_index] in lookup:
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            if cur_len > max_len: max_len = cur_len
            lookup.add(s[_index])
        return max_len
# @lc code=end

