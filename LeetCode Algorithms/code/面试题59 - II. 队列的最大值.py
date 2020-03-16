class MaxQueue:

    def __init__(self):
        self.queue_list = []

    def max_value(self) -> int:
        return max(self.queue_list) if self.queue_list else -1

    def push_back(self, value: int) -> None:
        self.queue_list.append(value)

    def pop_front(self) -> int:
        return self.queue_list.pop(0) if self.queue_list else -1


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()