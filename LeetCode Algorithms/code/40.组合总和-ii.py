#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#

# @lc code=start
class Solution:
    # def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
    @classmethod
    def combinationSum2(self, candidates, target):
        res = []
        if not candidates: return res

        candidates = sorted(candidates)
        length = len(candidates)

        # 回溯法标准模板
        def backtrack_method(i, temp_sum, temp_list):
            if temp_sum == target:
                res.append(temp_list)
                return

            for _index in range(i, length):
                if temp_sum + candidates[_index] > target: break    # 剪枝

                if _index > i and candidates[_index] == candidates[_index - 1]: continue    # 剪枝
                backtrack_method(_index + 1, temp_sum + candidates[_index], temp_list + [candidates[_index]])

        backtrack_method(0, 0, [])

        return res
        
# @lc code=end

print (Solution.combinationSum2(candidates = [10,1,2,7,6,1,5], target = 8,))