#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#

# @lc code=start
class Solution:
    @classmethod
    def reverseVowels(self, s: str) -> str:
        o_list = ['a','e','i','o','u','A','E','I','O','U']
        s_list = list(s)
        left, right = 0, len(s_list) - 1
        while left < right:
            if s_list[left] in o_list:
                while left < right:
                    if s_list[right] in o_list:
                        s_list[left], s_list[right] = s_list[right], s_list[left]
                        break
                    else:
                        right -= 1
            else:
                left +=
        return ''.join(s_list)

        # o_list = ['a','e','i','o','u','A','E','I','O','U']
        # s_list = list(s)
        # left, right = 0, len(s_list) - 1
        # while left < right:
        #     if s_list[left] not in o_list:
        #         left += 1
        #         continue
        #     if s_list[right] not in o_list:
        #         right -= 1
        #         continue
        #     s_list[left], s_list[right] = s_list[right], s_list[left]
        #     left += 1; right -= 1
        # return ''.join(s_list)

# @lc code=end

print (Solution.reverseVowels(s = "race car"))