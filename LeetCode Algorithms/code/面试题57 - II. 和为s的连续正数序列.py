# -*- coding: UTF-8 -*-

class Solution:
    @classmethod
    def findContinuousSequence(self, target: int):
        res = []
        if target == 1: return [1]
        for _index in range(1, target):
            if _index < target // 2 + 1:
                _sum = 0
                _temp_list = []
                while _sum <= target:
                    if _sum == target and _temp_list not in res:
                        res.append(_temp_list)
                        break
                    _temp_list.append(_index)
                    _sum += _index
                    _index += 1
        return res

if __name__ == "__main__":
    print (Solution.findContinuousSequence(target = 3))