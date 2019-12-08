#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 马拉车算法 - 求最长回文串
        if len(s) == 0: return ''
        temp_s = '#' + '#'.join(s) + '#'

        # 已遍历的最大右边界
        mx = 0
        # 对应的中心点
        mid = 0

        length = len(temp_s)
        # 扩散半径数组p，最长回文扩散半径初始值为1或者0，
        p = [1]*length

        for _index in range(length):
            if _index < mx:
                """
                    O(n)遍历每个字符对应的扩散半径
                    _index 对应的镜像为：2*mid - 1
                """
                p[_index] = min(mx - _index, p[2*mid - _index])

            while (_index - p[_index] >= 0 and _index + p[_index] < length and temp_s[_index - p[_index]] == temp_s[_index + p[_index]]):
                p[_index] += 1

            if _index + p[_index] > mx:
                mx = _index + p[_index]
                mid = _index
        maxr = max(p)
        ans = p.index(maxr)
        maxr -= 1    # 实际扩散半径应该减 1
        
        return temp_s[ans - maxr: ans + maxr + 1].replace('#', '')
# @lc code=end

