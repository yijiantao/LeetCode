# -*- coding: UTF-8 -*-
"""
    一、定义
        桥梁模式又叫桥接模式，定义如下：将抽象与实现解耦（注意此处的抽象和实现，并非抽象类和实现类的那种关系，而是一种角色的关系，这里需要好好区分一下），可以使其独立变化。
        在形如上例中，Pen只负责画，但没有形状，它终究是不知道要画什么的，所以我们把它叫做抽象化角色；而Shape是具体的形状，我们把它叫做实现化角色。
        抽象化角色和实现化角色是解耦的，这也就意味着，所谓的桥，就是抽象化角色的抽象类和实现化角色的抽象类之间的引用关系。

    二、场景
        在介绍原型模式的一节中，我们举了个图层的例子，这一小节内容，我们同样以类似画图的例子，说明一种结构类设计模式：桥梁模式。
        在一个画图程序中，常会见到这样的情况：有一些预设的图形，如矩形、圆形等，
        还有一个对象-画笔，调节画笔的类型（如画笔还是画刷，还是毛笔效果等）并设定参数（如颜色、线宽等），选定图形，就可以在画布上画出想要的图形了。
        要实现以上需求，先从最抽象的元素开始设计，即形状和画笔（暂时忽略画布，同时忽略画笔参数，只考虑画笔类型）。
"""


class Shape:    # 形状 shape 对象（最高级抽象的形式）
    name = ""
    param = ""

    def __init__(self, *param):
        pass

    def getName(self):
        return self.name

    def getParam(self):
        return self.name, self.param


class Pen:    # 画笔 pen 对象（最高级抽象的形式）
    shape = ""
    type = ""

    def __init__(self, shape):
        self.shape = shape

    def draw(self):
        pass

# 开始构造多种形状类
class Rectangle(Shape):    # 矩形类
    def __init__(self, long, width):
        self.name = "Rectangle"
        self.param = "Long:%s Width:%s" % (long, width)
        print("Create a rectangle:%s" % self.param)


class Circle(Shape):    # 圆形类
    def __init__(self, radius):
        self.name = "Circle"
        self.param = "Radius:%s" % radius
        print("Create a circle:%s" % self.param)


# 开始构造多种画笔类
class NormalPen(Pen):    # 普通画笔类
    def __init__(self, shape):
        Pen.__init__(self, shape)
        self.type = "Normal Line"

    def draw(self):
        print("DRAWING %s:%s----PARAMS:%s" %
              (self.type, self.shape.getName(), self.shape.getParam()))


class BrushPen(Pen):    # 画刷类
    def __init__(self, shape):
        Pen.__init__(self, shape)
        self.type = "Brush Line"

    def draw(self):
        print("DRAWING %s:%s----PARAMS:%s" %
              (self.type, self.shape.getName(), self.shape.getParam()))


if __name__ == "__main__":
    
    """
        开始画画，业务逻辑开始...
    """
    normal_pen = NormalPen(Rectangle("20cm", "10cm"))
    brush_pen = BrushPen(Circle("15cm"))
    normal_pen.draw()
    brush_pen.draw()
