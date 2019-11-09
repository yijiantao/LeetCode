#
# @lc app=leetcode.cn id=641 lang=python3
#
# [641] 设计循环双端队列
#

# @lc code=start
class MyCircularDeque:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.deque_length = k
        self.deque_list = []
        

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if len(self.deque_list) >= self.deque_length:
            return False
        self.deque_list = [value] + self.deque_list
        return True
        

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if len(self.deque_list) >= self.deque_length:
            return False
        self.deque_list = self.deque_list + [value]
        return True
        

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self.deque_list and len(self.deque_list) >= 1:
            del self.deque_list[0]
            return True
        return False
        

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self.deque_list and len(self.deque_list) >= 1:
            del self.deque_list[-1]
            return True
        return False
        

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.deque_list and len(self.deque_list) >= 1:
            get_value = self.deque_list[0]
            # del self.deque_list[0]
            return get_value
        return -1
        

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.deque_list and len(self.deque_list) >= 1:
            get_value = self.deque_list[-1]
            # del self.deque_list[-1]
            return get_value
        return -1

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        if len(self.deque_list) < 1:
            return True
        return False
        

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        if len(self.deque_list) == self.deque_length:
            return True
        return False


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
# @lc code=end

