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
        return sorted(candidates)
        
# @lc code=end

print (Solution.combinationSum2(candidates = [10,1,2,7,6,1,5], target = 8,))