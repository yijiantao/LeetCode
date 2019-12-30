#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        # s 为奇数长度时直接返回 False
        if len(s) % 2: return False
        if len(s) == 0: return True
        
        # 构造栈进行解题
        judge_str_dict = {')':'(', ']':'[', '}':'{'}
        stack = []
        for char in s:
            if char in judge_str_dict.keys():
                top_element = stack.pop() if stack else '#'

                if judge_str_dict[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack
# @lc code=end

