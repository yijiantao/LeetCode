#
# @lc app=leetcode.cn id=165 lang=python3
#
# [165] 比较版本号
#

# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # 了解 itertools.zip_longest 函数的用法，对比区分 zip()函数
        import itertools
        for ver_1_index, ver_2_index in itertools.zip_longest(version1.split('.'), version2.split('.'), fillvalue = 0):
            if int(ver_1_index) != int(ver_2_index): return 1 if int(ver_1_index) > int(ver_2_index) else -1
        return 0
# @lc code=end
