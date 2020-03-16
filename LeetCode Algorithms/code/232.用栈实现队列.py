#
# @lc app=leetcode.cn id=232 lang=python3
#
# [232] 用栈实现队列
#

# @lc code=start
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_list = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.queue_list.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.queue_list:
            return self.queue_list.pop(0)

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.queue_list:
            return self.queue_list[0]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if not self.queue_list:
            return True
        return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end

