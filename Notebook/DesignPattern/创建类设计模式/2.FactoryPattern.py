# -*- coding: UTF-8 -*-
"""
    工厂模式的定义如下：定义一个用于创建对象的接口，让子类决定实例化哪个类。
    工厂方法使一个类的实例化延迟到其子类。
    其产品类定义产品的公共属性和接口，工厂类定义产品实例化的“方式”。

    举例：肥仔快乐餐的生产 “汉堡+饮料” （工厂类）

    如下：
    1、Burger，Beverage，都可以认为是该快餐店的产品，由于只提供了抽象方法，我们把它们叫抽象产品类，
    而cheese burger等4个由抽象产品类衍生出的子类，叫作具体产品类。

    2、foodFactory为抽象的工厂类，
    而burgerFactory，snackFactory，beverageFactory为具体的工厂类。
"""


class Burger():    # 汉堡主食

    name = ""
    price = 0.0

    def getPrice(self):
        return self.price

    def setPrice(self, price):
        self.price = price

    def getName(self):
        return self.name


class cheeseBurger(Burger):    # 芝士汉堡包

    def __init__(self):
        self.name = "cheese burger"
        self.price = 10.0


class spicyChickenBurger(Burger):    # 香辣鸡腿汉堡
    def __init__(self):
        self.name = "spicy chicken burger"
        self.price = 15.0


class Beverage():    # 饮料
    name = ""
    price = 0.0
    type = "BEVERAGE"

    def getPrice(self):
        return self.price

    def setPrice(self, price):
        self.price = price

    def getName(self):
        return self.name


class coke(Beverage):    # 可乐
    def __init__(self):
        self.name = "coke"
        self.price = 4.0


class milk(Beverage):    # 牛奶
    def __init__(self):
        self.name = "milk"
        self.price = 5.0


class foodFactory():    # 抽象工厂类
    type = ""

    def createFood(self, foodClass):
        print(self.type, " factory produce a instance.")
        foodIns = foodClass()
        return foodIns


class burgerFactory(foodFactory):    # 具体工厂类
    def __init__(self):
        self.type = "BURGER"


class beverageFactory(foodFactory):    # 具体工厂类
    def __init__(self):
        self.type = "BEVERAGE"


class simpleFoodFactory():    # 省去了将工厂实例化的过程。这种模式就叫做简单工厂模式。
    @classmethod
    def createFood(cls, foodClass):
        print("Simple factory produce a instance.")
        foodIns = foodClass()
        return foodIns


if __name__ == "__main__":
    """
        Q: 在业务场景中，工厂模式是如何“生产”产品的呢？
        A: 业务中先生成了工厂，然后用工厂中的createFood方法和对应的参数直接生成产品实例。
    """

    burger_factory = burgerFactory()
    beverage_factory = beverageFactory()

    cheese_burger = burger_factory.createFood(cheeseBurger)
    print(cheese_burger.getName(), cheese_burger.getPrice())

    coke_drink = beverage_factory.createFood(coke)
    print(coke_drink.getName(), coke_drink.getPrice())
