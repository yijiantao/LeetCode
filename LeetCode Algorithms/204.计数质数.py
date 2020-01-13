#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#

# @lc code=start
class Solution:
    def countPrimes(self, n: int) -> int:
        # 埃拉托斯特尼筛法，简称埃氏筛选法，也叫厄拉多塞筛法
        ## 当筛到当前数x时，在区间[x^2, n)中x的倍数全排除掉！
        ## 算法思想：还是要看清楚埃氏筛这一句：要得到自然数n以内的全部质数，必须把不大于根号n的所有质数的倍数剔除，剩下的就是质数。
        if n < 2: return 0    # 最小质数是2
        isPrime= [1] * n
        isPrime[0] = isPrime[1] = 0    # 0和1不是质数，先排除掉

        # 埃氏筛选法，把不大于根号n的所有质数的倍数都排除
        for _index in range(2, int(n ** 0.5) + 1):
            if isPrime[_index]:
                isPrime[_index * _index: n : _index] = [0] * ((n - 1 - _index * _index) // _index + 1)

        return sum(isPrime)
# @lc code=end

