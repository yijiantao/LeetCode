# -*- coding: UTF-8 -*-
"""
    一、定义
    策略模式定义如下：定义一组算法，将每个算法都封装起来，并使他们之间可互换。
    策略模式让算法可以独立于使用它的客户变化。
    每一个封装算法的类称之为策略(Strategy)类，策略模式提供了一种可插入式(Pluggable)算法的实现方案;
    以下面例子为例，customer类扮演的角色（Context）直接依赖抽象策略的接口，在具体策略实现类中即可定义个性化的策略方式，且可以方便替换。

    二、场景（客户消息通知）
    假设某司维护着一些客户资料，需要在该司有新产品上市或者举行新活动时通知客户。
    现通知客户的方式有两种：短信通知、邮件通知。应如何设计该系统的客户通知部分？
    为解决该问题，我们先构造客户类，包括客户常用的联系方式和基本信息，同时也包括要发送的内容。
"""


class customer:    # 构造客户类
    customer_name = ""
    snd_way = ""
    info = ""
    phone = ""
    email = ""

    def setPhone(self, phone):
        self.phone = phone

    def setEmail(self, mail):
        self.email = mail

    def getPhone(self):
        return self.phone

    def getEmail(self):
        return self.email

    def setInfo(self, info):
        self.info = info

    def setName(self, name):
        self.customer_name = name

    def setBrdWay(self, snd_way):
        self.snd_way = snd_way

    def sndMsg(self):
        self.snd_way.send(self.info)


class msgSender:    # 构建 发送方式类
    dst_code = ""

    def setCode(self, code):
        self.dst_code = code

    def send(self, info):
        pass


class emailSender(msgSender):
    def send(self, info):
        print("EMAIL_ADDRESS:%s EMAIL:%s" % (self.dst_code, info))


class textSender(msgSender):
    def send(self, info):
        print("TEXT_CODE:%s EMAIL:%s" % (self.dst_code, info))


if __name__ == "__main__":
    """
        在业务场景中将发送方式作为策略，根据需求进行发送。
    """
    customer_x = customer()
    customer_x.setName("CUSTOMER_X")
    customer_x.setPhone("10023456789")
    customer_x.setEmail("customer_x@xmail.com")
    customer_x.setInfo("Welcome to our new party!")
    text_sender = textSender()
    text_sender.setCode(customer_x.getPhone())
    customer_x.setBrdWay(text_sender)
    customer_x.sndMsg()
    mail_sender = emailSender()
    mail_sender.setCode(customer_x.getEmail())
    customer_x.setBrdWay(mail_sender)
    customer_x.sndMsg()
