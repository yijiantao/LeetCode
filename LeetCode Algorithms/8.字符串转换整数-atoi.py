#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

# @lc code=start
class Solution:
    def myAtoi(self, str: str) -> int:
        flag_list = ['-', '+']
        int_list = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        strStr = str.strip()
        if not strStr: return 0
        if strStr[0] not in int_list and strStr[0] not in flag_list: return 0
        temp_strStr = ''
        for _index in range(len(strStr)):
            if _index == 0 and strStr[_index] in flag_list:
                temp_strStr = strStr[_index]
            else:
                if strStr[_index] in int_list:
                    temp_strStr += strStr[_index]
                else:
                    break

        if not temp_strStr or temp_strStr in flag_list: return 0
        int_strStr = int(temp_strStr)
        if int_strStr > (2 ** 31 - 1): return (2 ** 31 - 1)
        if int_strStr < (-2 ** 31): return (-2 ** 31)
        return int_strStr

        # 方法二： 可尝试用正则表达式匹配！
 
# @lc code=end
