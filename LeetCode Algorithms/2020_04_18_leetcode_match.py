# -*- coding: UTF-8 -*-

class Solution:
    @classmethod
    def processQueries(self, n, relation, k):
        if not relation or (k - 1) == 0: return 0
        res_list = []
        k_index = k
        combina_list = [_v for _v in relation if (_v[0] == 0 and _v[1] != n - 1)]
        while k_index:
            k_index -= 1
            temp_combina = []
            for _v in relation:
                for _comb_v in combina_list:
                    if (_comb_v[-1] == _v[0]):
                        _temp_list = _comb_v[:-1] + _v
                        if (_temp_list not in combina_list):
                            temp_combina.append(_temp_list)
            combina_list = temp_combina
            for _comb_v in combina_list:
                if _comb_v[-1] == n - 1 and len(_comb_v) == k + 1 and _comb_v not in res_list:
                        res_list.append(_comb_v)
        
        return len(res_list)

    @classmethod
    def getTriggerTime(self, increase, requirements):
        if requirements == [[0,0,0]]: return [0]
        res = [-1 for _ in requirements]
        init_feature = [0, 0, 0]
        curTime = 0
        if not increase or not requirements: return res
        for _i in increase:
            init_feature = list(sum(_v) for _v in zip(init_feature, _i))
            curTime += 1
            for _index, _req in enumerate(requirements):
                if res[_index] == -1 and _req[0] <= init_feature[0] and _req[1] <= init_feature[1] and _req[2] <= init_feature[2]:
                    res[_index] = curTime

        return res

if __name__ == "__main__":
    # n = 5
    # relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]
    # k = 3
    increase = [[1,1,1]]
    requirements = [[0,0,0]]
    # print (Solution.processQueries(n, relation, k))
    print (Solution.getTriggerTime(increase, requirements))