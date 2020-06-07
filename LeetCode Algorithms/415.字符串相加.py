/*
 * @lc app=leetcode.cn id=415 lang=py
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        return (str(eval(num1+'+'+num2)))
// @lc code=end