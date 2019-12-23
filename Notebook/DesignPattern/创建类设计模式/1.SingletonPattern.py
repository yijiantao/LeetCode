# -*- coding: UTF-8 -*-
"""
    1. 单例模式：Ensure a class has only one instance, and provide a global point of access to it.
                （保证某一个类只有一个实例，而且在全局只有一个访问点）
    具体应用场景：【数据总线对象】即各个线程的访问只有一个全局访问点，即唯一的实例
    【说明】：在程序运行过程中，三个线程同时运行（运行结果的前三行先很快打印出来），
             而后分别占用总线资源（后三行每隔3秒打印一行）。虽然看上去总线Bus被实例化了三次，
             但实际上在内存里只有一个实例。
"""

import threading
import time
#这里使用方法__new__来实现单例模式
class Singleton(object):#抽象单例
    def __new__(cls, *args, **kw):
        if not hasattr(cls, '_instance'):
            orig = super(Singleton, cls)
            cls._instance = orig.__new__(cls, *args, **kw)
        return cls._instance
#总线
class Bus(Singleton):
    lock = threading.RLock()
    def sendData(self,data):
        self.lock.acquire()
        time.sleep(3)
        print ("Sending Signal Data...", data)
        self.lock.release()
#线程对象，为更加说明单例的含义，这里将Bus对象实例化写在了run里
class VisitEntity(threading.Thread):
    my_bus=""
    name=""
    def getName(self):
        return self.name
    def setName(self, name):
        self.name=name
    def run(self):
        self.my_bus=Bus()
        self.my_bus.sendData(self.name)

if  __name__=="__main__":
    for _index in range(3):
        print (f"Entity {_index} begin to run...")
        my_entity=VisitEntity()
        my_entity.setName("Entity_"+str(_index))
        my_entity.start()
