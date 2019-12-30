# -*- coding: UTF-8 -*-
"""
    装饰器模式（Decorator Pattern）允许向一个现有的对象添加新的功能，同时又不改变其结构。
    这种类型的设计模式属于结构型模式，它是作为现有的类的一个包装。
    这种模式创建了一个装饰类，用来包装原有的类，并在保持类方法签名完整性的前提下，提供了额外的功能。

    举例：
        快餐点餐系统，以其中的一个类作为主角：饮料类

    注意：
        装饰器模式和上一节说到的代理模式非常相似，可以认为，装饰器模式就是代理模式的一个特殊应用，
        两者的共同点是都具有相同的接口，不同点是侧重对主题类的过程的控制，而装饰模式则侧重对类功能的加强或减弱。
"""


class LogManager:
    """
        特殊功能点：log接口就是装饰器的定义，而Python的@语法部分则直接支持装饰器的使用。
                   如果要在快餐点餐系统中打印日志，该如何进行AOP改造呢？可以借助类的静态方法或者类方法来实现。
    """
    @staticmethod
    def log(func):
        def wrapper(*args):
            print("Visit Func %s" % func.__name__)
            return func(*args)
        return wrapper


class Beverage():
    name = ""
    price = 0.0
    type = "BEVERAGE"

    @LogManager.log    # 特殊功能点测试，装饰器修饰函数，打印日志
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


class drinkDecorator():    # 定义装饰器类
    def getName(self):
        pass

    def getPrice(self):
        pass


class iceDecorator(drinkDecorator):    # 如果饮料加冰的话，要在原价上加0.3元
    def __init__(self, beverage):
        self.beverage = beverage

    def getName(self):
        return self.beverage.getName()+" +ice"

    def getPrice(self):
        return self.beverage.getPrice()+0.3


class sugarDecorator(drinkDecorator):    # 如果饮料加糖的话，要原价上加0.5元
    def __init__(self, beverage):
        self.beverage = beverage

    def getName(self):
        return self.beverage.getName()+" +sugar"

    def getPrice(self):
        return self.beverage.getPrice()+0.5


if __name__ == "__main__":
    """
        构建好装饰器后，在具体的业务场景中，就可以与饮料类进行关联。
        以可乐+冰为例，示例业务场景如下：
    """
    coke_cola = coke()
    print("Name:%s" % coke_cola.getName())
    print("Price:%s" % coke_cola.getPrice())
    ice_coke = iceDecorator(coke_cola)
    print("Name:%s" % ice_coke.getName())
    print("Price:%s" % ice_coke.getPrice())
