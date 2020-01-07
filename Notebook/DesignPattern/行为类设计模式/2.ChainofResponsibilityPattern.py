# -*- coding: UTF-8 -*-
"""
    一、定义
        责任链模式的定义如下：使多个对象都有机会处理请求，从而避免了请求的发送者和接收者之间的耦合关系。
        将这些对象连成一条链，并沿着这条链传递该请求，直到有对象处理它为止。
        需要说明的是，责任链模式中的应该只有一个处理者，也就是说，下面例子中的“最终批准”为该对象所谓的“请求处理”。
    二、场景
        一个请假系统：员工若想要请3天以内（包括3天的假），只需要直属经理批准就可以了；
        如果想请3-7天，不仅需要直属经理批准，部门经理需要最终批准；如果请假大于7天，不光要前两个经理批准，也需要总经理最终批准。
        类似的系统相信大家都遇到过，那么该如何实现呢？首先想到的当然是if…else…，但一旦遇到需求变动，其臃肿的代码和复杂的耦合缺点都显现出来。
        简单分析下需求，“假条”在三个经理间是单向传递关系，像一条链条一样，因而，我们可以用一条“链”把他们进行有序连接。

        如下例：构造抽象经理类和各个层级的经理类...
"""


class manager():    # 构造抽象经理类
    successor = None
    name = ''

    def __init__(self, name):
        self.name = name

    def setSuccessor(self, successor):
        self.successor = successor

    def handleRequest(self, request):
        pass


class lineManager(manager):    # 生产线经理、直接上司
    def handleRequest(self, request):
        if request.requestType == 'DaysOff' and request.number <= 3:
            print('%s:%s Num:%d Accepted OVER' %
                  (self.name, request.requestContent, request.number))
        else:
            print('%s:%s Num:%d Accepted CONTINUE' %
                  (self.name, request.requestContent, request.number))
            if self.successor != None:
                self.successor.handleRequest(request)


class departmentManager(manager):    # 部门经理
    def handleRequest(self, request):
        if request.requestType == 'DaysOff' and request.number <= 7:
            print('%s:%s Num:%d Accepted OVER' %
                  (self.name, request.requestContent, request.number))
        else:
            print('%s:%s Num:%d Accepted CONTINUE' %
                  (self.name, request.requestContent, request.number))
            if self.successor != None:
                self.successor.handleRequest(request)


class generalManager(manager):    # 总经理、公司业务执行的最高负责人
    def handleRequest(self, request):
        if request.requestType == 'DaysOff':
            print('%s:%s Num:%d Accepted OVER' %
                  (self.name, request.requestContent, request.number))


class request():    # request类，封装了假期请求
    requestType = ''
    requestContent = ''
    number = 0


if __name__ == "__main__":

    """
        在具体的经理类中，可以通过setSuccessor接口来构建“责任链”，
        并在handleRequest接口中实现逻辑。场景类中实现如下：
    """

    line_manager = lineManager('LINE MANAGER')
    department_manager = departmentManager('DEPARTMENT MANAGER')
    general_manager = generalManager('GENERAL MANAGER')

    line_manager.setSuccessor(department_manager)
    department_manager.setSuccessor(general_manager)

    req = request()
    req.requestType = 'DaysOff'
    req.requestContent = 'Ask 1 day off'
    req.number = 1
    line_manager.handleRequest(req)

    req.requestType = 'DaysOff'
    req.requestContent = 'Ask 5 days off'
    req.number = 5
    line_manager.handleRequest(req)

    req.requestType = 'DaysOff'
    req.requestContent = 'Ask 10 days off'
    req.number = 10
    line_manager.handleRequest(req)
