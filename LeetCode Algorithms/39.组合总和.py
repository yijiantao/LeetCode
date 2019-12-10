#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if target == 0:
            return [[]]
        elif not candidates or target < min(candidates):
            return []    # 已经没有可组合项或全部大于target，则不可能还存在组合满足条件
        res = []
        for _index in candidates:
            # 剪枝，使用 过滤器函数 可避免出现排列不同的重复答案且免排序，
            # x > _index 和 x < _index都可以
            for _j in self.combinationSum(list(filter(lambda x: x <= _index, candidates)), target - _index):
                res.append([_index] + _j)
        return res
# @lc code=end

