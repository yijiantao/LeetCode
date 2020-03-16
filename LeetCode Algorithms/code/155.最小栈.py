#
# @lc app=leetcode.cn id=155 lang=python3
#
# [155] 最小栈
#

# @lc code=start
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack_dict = {'min_value': [], 'stack_list':[]}

    def push(self, x: int) -> None:
        if len(self.stack_dict['min_value']) == 0 or x <= self.stack_dict['min_value'][-1]:
            self.stack_dict['min_value'].append(x)
        
        self.stack_dict['stack_list'].append(x)
        return True

    def pop(self) -> None:
        top = self.stack_dict['stack_list'].pop(-1)

        if len(self.stack_dict['min_value']) and top == self.stack_dict['min_value'][-1]:
            self.stack_dict['min_value'].pop()
        return top

    def top(self) -> int:
        if len(self.stack_dict['stack_list']):
            return self.stack_dict['stack_list'][-1]
        return False

    def getMin(self) -> int:
        if len(self.stack_dict['min_value']):
            return self.stack_dict['min_value'][-1]
        return None


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

