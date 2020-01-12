# -*- coding -*-
"""
    一、定义：
        迭代器模式的定义如下：它提供一种方法，访问一个容器对象中各个元素，而又不需要暴露对象的内部细节。

    二、场景：
        在python中，迭代器并不用举太多的例子，因为python中的迭代器应用实在太多了。
        （不管是python还是其它很多的编程语言中，实际上迭代器都已经纳入到了常用的库或者包中）。
        而且在当前，也几乎没有人专门去开发一个迭代器，
        而是直接去使用list、string、set、dict等python可迭代对象，
        或者直接使用__iter__和next函数来实现迭代器。
        如下例：
"""


class MyIter(object):

    def __init__(self, n):
        self.index = 0
        self.n = n

    def __iter__(self):
        # 注意__iter__方法中的返回值，由于直接返回了self，因而该迭代器是无法重复迭代的
        return self    # 只能打印一遍平方值

        # 在__iter__中不返回实例，而再返回一个对象
        # return MyIter(self.n)    # 在每次迭代时都可以将迭代器“初始化”，就可以多次迭代了

    def __next__(self):
        if self.index < self.n:
            value = self.index**2
            self.index += 1
            return value
        else:
            raise StopIteration()


if __name__ == "__main__":
    """
        迭代器，举例一：
    """
    x_square = MyIter(10)
    print(x_square)
    for x in x_square:
        print(x)
    # for x in x_square:
    #     print(x)
    """
        迭代器，举例二：
    """
    lst = ["hello Alice", "hello Bob", "hello Eve"]
    lst_iter = iter(lst)
    print(lst_iter)
    print(lst_iter.__next__())
    print(lst_iter.__next__())
    print(lst_iter.__next__())
    print(lst_iter.__next__())    # 超限，抛 StopIteration 异常
