#
# @lc app=leetcode.cn id=12 lang=python3
#
# [12] 整数转罗马数字
#

# @lc code=start
class Solution:
    def intToRoman(self, num: int) -> str:
        int_value = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        roman_value = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        result = ''
        _index = 0
        while (num > 0 and _index < len(roman_value)):
            if num >= int_value[_index]:
                result += roman_value[_index]
                num -= int_value[_index]
            else:
                _index += 1
        return result
# @lc code=end

