#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    @classmethod
    def coinChange(self, coins, amount: int) -> int:

        if amount == 0: return 0
        if coins:
            # 回溯法 + 剪枝
            coins.sort(reverse=True)

            len_coins, res = len(coins), amount + 1

            def countCoins(_index, target, count):
                nonlocal res
                if not target:
                    res = min(res, count)

                for _i in range(_index, len_coins):
                    if coins[_i] <= target < coins[_i] * (res - count):  # 剪枝
                        countCoins(_i, target - coins[_i], count + 1)

            for _index in range(len_coins):
                
                countCoins(_index, amount, 0)

        return -1 if res > amount else res
        
# @lc code=end

print(Solution.coinChange(coins = [1, 2, 5], amount = 11))