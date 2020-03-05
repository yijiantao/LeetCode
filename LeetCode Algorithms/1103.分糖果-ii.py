#
# @lc app=leetcode.cn id=1103 lang=python3
#
# [1103] 分糖果 II
#

# @lc code=start
class Solution:
    @classmethod
    def distributeCandies(self, candies: int, num_people: int):
        # 简单方法一：
        # res = [0 for _ in range(num_people)]
        # _index, candies_index = -1, 0
        # while True:
        #     candies_index += 1
        #     _index += 1
        #     _index %= num_people
        #     if candies > candies_index:
        #         res[_index] += candies_index
        #         candies -= candies_index
        #     else:
        #         res[_index] += candies
        #         break
            
        # 简单方法二：
        res = [0] * num_people
        _index = 0
        while candies > 0:
            res[_index % num_people] += min(_index + 1, candies)
            candies -= (_index + 1)
            _index += 1
        return res
# @lc code=end

print (Solution.distributeCandies(candies = 7, num_people = 4))