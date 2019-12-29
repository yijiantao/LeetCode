#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#

# @lc code=start
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # 杨辉三角 通项公式
        # 杨辉三角正好是二次项的展开式,(1+x)的n次幂的系数,
        # 有通项公式C(n-1,m-1)=(n-1)!/[(m-1)!(n-m)!] 
        # 而研究每一项后,发现他们的规律,如 C(4,1)=C(4,0)*4/1,
        #                               C(4,2)=C(4,1)*3/2,
        #                               C(4,3)=C(4,2)*2/3,
        #                               C(4,4)=C(4,3)*1/4

        _index = 1
        res = []
        for _row in range(rowIndex + 1):
            res.append(int(_index))
            _index = _index * (rowIndex - _row) / (_row + 1)
        return res
# @lc code=end

