#
# @lc app=leetcode.cn id=167 lang=python3
#
# [167] 两数之和 II - 输入有序数组
#

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 暴力法直接超时，，，
        # for _index, _value in enumerate(numbers):
        #     for _i in range(_index + 1, len(numbers)):
        #         if _value + numbers[_i] == target:
        #             return [_index + 1, _i + 1]

        # 用哈希表法
        dict = {}
        for _index in range(len(numbers)):
            if numbers[_index] in dict:
                return sorted([_index + 1, dict[numbers[_index]] + 1])
            else: dict[target - numbers[_index]] = _index

        return False
# @lc code=end

