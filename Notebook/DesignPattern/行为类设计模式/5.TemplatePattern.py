# -*- coding -*-
"""
    一、定义：
        模板模式定义如下：定义一个操作中的算法的框架，而将一些步骤延迟到子类中，使得子类可以不改变一个算法的结构即可重新定义该算法的某些特定的步骤。
        子类实现的具体方法叫作基本方法，实现对基本方法高度的框架方法，叫作模板方法。

    二、场景： [股票查询客户端]
        投资股票是种常见的理财方式，我国股民越来越多，实时查询股票的需求也越来越大。
        今天，我们通过一个简单的股票查询客户端来认识一种简单的设计模式：模板模式。
        根据股票代码来查询股价分为如下几个步骤：登录、设置股票代码、查询、展示。构造如下的虚拟股票查询器：
"""


class StockQueryDevice():    # 虚拟股票查询器
    stock_code = "0"
    stock_price = 0.0

    def login(self, usr, pwd):
        pass

    def setCode(self, code):
        self.stock_code = code

    def queryPrice(self):  # [模板模式]中，在父类中提供的模板方法
        pass

    def showPrice(self):  # [模板模式]中，在父类中提供的模板方法
        pass

    def operateQuery(self, usr, pwd, code):  # [模板模式]中，在父类中提供的模板方法
        if not self.login(usr, pwd):
            return False
        self.setCode(code)
        self.queryPrice()
        self.showPrice()
        return True


class WebAStockQueryDevice(StockQueryDevice):
    # [WebA查询器类] 根据不同的查询机构和查询方式，来通过继承的方式实现其对应的股票查询器类。
    def login(self, usr, pwd):
        if usr == "myStockA" and pwd == "myPwdA":
            print("Web A:Login OK... user:%s pwd:%s" % (usr, pwd))
            return True
        else:
            print("Web A:Login ERROR... user:%s pwd:%s" % (usr, pwd))
            return False

    def queryPrice(self):
        print("Web A Querying...code:%s " % self.stock_code)
        self.stock_price = 20.00

    def showPrice(self):
        print("Web A Stock Price...code:%s price:%s" %
              (self.stock_code, self.stock_price))


class WebBStockQueryDevice(StockQueryDevice):
    # [WebB查询器类] 根据不同的查询机构和查询方式，来通过继承的方式实现其对应的股票查询器类。
    def login(self, usr, pwd):
        if usr == "myStockB" and pwd == "myPwdB":
            print("Web B:Login OK... user:%s pwd:%s" % (usr, pwd))
            return True
        else:
            print("Web B:Login ERROR... user:%s pwd:%s" % (usr, pwd))
            return False

    def queryPrice(self):
        print("Web B Querying...code:%s " % self.stock_code)
        self.stock_price = 30.00

    def showPrice(self):
        print("Web B Stock Price...code:%s price:%s" %
              (self.stock_code, self.stock_price))


if __name__ == "__main__":
    web_a_query_dev = WebAStockQueryDevice()
    web_a_query_dev.operateQuery("myStockA", "myPwdA", "12345")
