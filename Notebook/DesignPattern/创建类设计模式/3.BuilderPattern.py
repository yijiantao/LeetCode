# -*- coding: UTF-8 -*-
"""
    建造者模式的定义如下：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。

    举例：肥仔快乐餐的订餐方式（订单类）
    
"""

class Burger():    # 汉堡类
    name = ""
    price = 0.0

    def getPrice(self):
        return self.price

    def setPrice(self, price):
        self.price = price

    def getName(self):
        return self.name

class cheeseBurger(Burger):
    def __init__(self):
        self.name = "cheese burger"
        self.price = 10.0

class spicyChickenBurger(Burger):
    def __init__(self):
        self.name = "spicy chicken burger"
        self.price = 15.0

class Beverage():    # 饮料类
    name = ""
    price = 0.0
    type = "BEVERAGE"

    def getPrice(self):
        return self.price

    def setPrice(self, price):
        self.price = price

    def getName(self):
        return self.name

class coke(Beverage):
    def __init__(self):
        self.name = "coke"
        self.price = 4.0

class milk(Beverage):
    def __init__(self):
        self.name = "milk"
        self.price = 5.0

class order():
    """
        最终，我们是要建造一个订单，因而，需要一个订单类。
        假设，一个订单，包括一份主食，一种饮料。（省去一些异常判断）
    """
    burger = ""
    beverage = ""

    def __init__(self, orderBuilder):
        self.burger = orderBuilder.bBurger
        self.beverage = orderBuilder.bBeverage

    def show(self):
        print("Burger:%s" % self.burger.getName())
        print("Beverage:%s" % self.beverage.getName())

class orderBuilder():    # 建造者模式中所谓的“建造者”
    bBurger = ""
    bBeverage = ""

    def addBurger(self, xBurger):
        self.bBurger = xBurger

    def addBeverage(self, xBeverage):
        self.bBeverage = xBeverage

    def build(self):
        return order(self)

if __name__ == "__main__":
    """
        Q: 为什么不在order类中把所有内容都填上，而非要用builder去创建？
        A: 建造者模式的作用，就是将“构建”和“表示”分离，以达到解耦的作用。
           在上面订单的构建过程中，如果将order直接通过参数定义好（其构建与表示没有分离），
           同时在多处进行订单生成，此时需要修改订单内容，则需要一处处去修改，业务风险也就提高了不少。
    """
    order_builder = orderBuilder()
    order_builder.addBurger(spicyChickenBurger())
    order_builder.addBeverage(milk())
    order_1 = order_builder.build()
    order_1.show()
