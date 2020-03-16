#
# @lc app=leetcode.cn id=994 lang=python3
#
# [994] 腐烂的橘子
#

# @lc code=start


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
         # 初始时间
        minute = 0
        raw_length, col_length = len(grid), len(grid[0])
        # 网格每一个坐标的访问状态
        visit = [[False] * col_length for _ in range(raw_length)]

        stack = [[_raw_index, _col_index] for _raw_index in range(raw_length) for _col_index in range(col_length) if grid[_raw_index][_col_index] == 2]

        # 坏橘子传染好橘子的四个方向，上下左右
        direction = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        while True:
            # 初始化一个stack_next，把这一轮变坏的橘子装进里面
            stack_next = []
            # 开始对坏橘子进行审查，主要是看上下左右有没有好橘子
            while stack:
                _raw_index, _col_index = stack.pop()
                for d in direction:
                    _raw_index_new, _col_index_new = _raw_index + d[0], _col_index + d[1]
                    if -1 < _raw_index_new < raw_length and -1 < _col_index_new < col_length and not visit[_raw_index_new][_col_index_new] and grid[_raw_index_new][_col_index_new] == 1:
                        visit[_raw_index_new][_col_index_new] = True
                        grid[_raw_index_new][_col_index_new] = 2
                        stack_next.append([_raw_index_new, _col_index_new])

            # 如果橘子都检查完了发现再无其他坏橘子，终止循环
            if not stack_next: break
            stack = stack_next
            minute += 1
        
        return -1 if ['_' for _raw_index in range(raw_length) for _col_index in range(col_length) if grid[_raw_index][_col_index] == 1] else minute
                        # @lc code=end
