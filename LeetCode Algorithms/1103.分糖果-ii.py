#
# @lc app=leetcode.cn id=1103 lang=python3
#
# [1103] 分糖果 II
#

# @lc code=start
class Solution:
    @classmethod
    def distributeCandies(self, candies: int, num_people: int):
        res = [0 for _ in range(num_people)]
        _index, candies_index = -1, 0
        while True:
            candies_index += 1
            _index += 1
            _index %= num_people
            if candies > candies_index:
                res[_index] += candies_index
                candies -= candies_index
            else:
                res[_index] += candies
                break
            
        return res
# @lc code=end

print (Solution.distributeCandies(candies = 10, num_people = 3))