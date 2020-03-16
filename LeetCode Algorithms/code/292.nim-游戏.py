#
# @lc app=leetcode.cn id=292 lang=python3
#
# [292] Nim 游戏
#

# @lc code=start
class Solution:
    def canWinNim(self, n: int) -> bool:
        # 你先手，你想赢，需要的条件是：当你拿石子的时候，石子不是四的倍数；
        # 因为在这种情况下不管你取走多少石头，总会为你的对手留下几块，使得他可以在游戏中打败你。

        # 你后手，你想赢，需要的条件是：当对手拿石子的时候，石子是四的倍数；
        return (n % 4 != 0)
# @lc code=end

