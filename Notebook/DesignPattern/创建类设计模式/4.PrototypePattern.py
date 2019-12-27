# -*- coding: UTF-8 -*-
"""
    原型模式的定义如下：用原型实例指定创建对象的种类，并且通过复制这些原型创建新的对象。
                      需要注意一点的是，进行clone操作后，新对象的构造函数没有被二次执行，
                      新对象的内容是从内存里直接拷贝的。

    举例：类似于Photoshop的平面设计软件，一定都知道图层的概念。
          图层概念的提出，使得设计、图形修改等操作更加便利。
          设计师既可以修改和绘制当前图像对象，又可以保留其它图像对象，逻辑清晰，且可以及时得到反馈。
          本代码，将以图层为主角，介绍原型模式。
    
"""
from copy import copy, deepcopy


class simpleLayer:    # 图层类
    background = [0, 0, 0, 0]
    content = "blank"

    def getContent(self):
        return self.content

    def getBackgroud(self):
        return self.background

    def paint(self, painting):
        self.content = painting

    def setParent(self, p):
        self.background[3] = p

    def fillBackground(self, back):
        self.background = back

    # 如果需要再生成一个同样的图层，再填充同样的颜色
    # 可以用复制的方法来实现，而复制（clone）这个动作，就是原型模式的精髓了。
    def clone(self):
        return copy(self)

    def deep_clone(self):
        return deepcopy(self)


if __name__ == "__main__":
    """
        Q: clone和deep_clone有什么区别呢？
        A: 大多数编程语言中，都会涉及到深拷贝和浅拷贝的问题，
           一般来说，浅拷贝会拷贝对象内容及其内容的引用或者子对象的引用，但不会拷贝引用的内容和子对象本身；
           浅拷贝后，直接对拷贝后引用（这里的数组）进行操作，原始对象中该引用的内容也会变动。

           而深拷贝不仅拷贝了对象和内容的引用，也会拷贝引用的内容。
           所以，一般深拷贝比浅拷贝复制得更加完全，但也更占资源（包括时间和空间资源）。
    """
    dog_layer = simpleLayer()
    dog_layer.paint("Dog")
    dog_layer.fillBackground([0, 0, 255, 0])
    print("Background:", dog_layer.getBackgroud())
    print("Painting:", dog_layer.getContent())

    # 再画一只同样狗, 而不需要重新新建图层了
    another_dog_layer = dog_layer.clone()
    print("Background:", another_dog_layer.getBackgroud())
    print("Painting:", another_dog_layer.getContent())
