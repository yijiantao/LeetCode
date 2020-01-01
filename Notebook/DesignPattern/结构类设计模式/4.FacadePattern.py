# -*- coding: UTF-8 -*-
"""
    应用场景举例：
    假设有一组火警报警系统，由三个子元件构成：一个警报器，一个喷水器，一个自动拨打电话的装置。
    其抽象如下：警报器类、喷水器类和紧急拨号类
"""


class AlarmSensor:    # 警报器类
    def run(self):
        print("Alarm Ring...")


class WaterSprinker:    # 喷水器类
    def run(self):
        print("Spray Water...")


class EmergencyDialer:    # 紧急拨号类
    def run(self):
        print("Dial 119...")


class EmergencyFacade:    # 门面模式类, 对象进行封装
    def __init__(self):
        self.alarm_sensor = AlarmSensor()
        self.water_sprinker = WaterSprinker()
        self.emergency_dialer = EmergencyDialer()

    def runAll(self):
        self.alarm_sensor.run()
        self.water_sprinker.run()
        self.emergency_dialer.run()


if __name__ == "__main__":
    """
        一、普通场景，功能调用实现：
        在业务中如果需要将三个部件启动，
        例如，如果有一个烟雾传感器，检测到了烟雾。在业务环境中需要做如下操作：
    """
    alarm_sensor = AlarmSensor()
    water_sprinker = WaterSprinker()
    emergency_dialer = EmergencyDialer()
    alarm_sensor.run()
    water_sprinker.run()
    emergency_dialer.run()

    """
        二、外观（门面）模式封装后，功能调用实现：
        但如果在多个业务场景中需要启动三个部件，减少重复代码,需要将其进行封装.
        在设计模式中，被封装成的新对象，叫做门面,门面模式构建如下。
    """
    emergency_facade = EmergencyFacade()
    emergency_facade.runAll()
