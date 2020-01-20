# -*- coding: UTF-8 -*-
"""
    一、定义：
        备忘录模式定义如下：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。
        这样以后就可以将该对象恢复到原来保存的状态。
        在备忘录模式中，如果要保存的状态多，可以创造一个备忘录管理者角色来管理备忘录。

    二、场景：
        打过游戏的朋友一定知道，大多数游戏都有保存进度的功能，如果一局游戏下来，忘保存了进度，那么下次只能从上次进度点开始重新打了。
        一般情况下，保存进度是要存在可持久化存储器上，本例中先以保存在内存中来模拟实现该场景的情形。

"""

import random

class GameCharacter():    # 模拟一个战斗角色为例。首先，创建游戏角色。
    """
        GameCharacter定义了基本的生命值、攻击值、防御值以及实现角色状态控制的方法
    """

    vitality = 0
    attack = 0
    defense = 0

    def displayState(self):
        print ('Current Values:')
        print ('Life:%d' % self.vitality)
        print ('Attack:%d' % self.attack)
        print ('Defence:%d' % self.defense)

    def initState(self, vitality, attack, defense):
        self.vitality = vitality
        self.attack = attack
        self.defense = defense

    def saveState(self):
        return Memento(self.vitality, self.attack, self.defense)

    def recoverState(self, memento):
        self.vitality = memento.vitality
        self.attack = memento.attack
        self.defense = memento.defense


class FightCharactor(GameCharacter):    # FightCharactor实现具体的“战斗”接口
    def fight(self):
        self.vitality -= random.randint(1, 10)


class Memento:    # 为实现保存进度的细节，还需要一个备忘录，来保存进度。
    vitality = 0
    attack = 0
    defense = 0

    def __init__(self, vitality, attack, defense):
        self.vitality = vitality
        self.attack = attack
        self.defense = defense

if __name__=="__main__":
    """
        实际业务场景：
        由生命值变化可知，先保存状态值，经过一轮打斗后，生命值由100变为91，而后恢复状态值，生命值又恢复成100。
    """
    game_chrctr = FightCharactor()
    game_chrctr.initState(100,79,60)
    game_chrctr.displayState()
    memento = game_chrctr.saveState()
    game_chrctr.fight()
    game_chrctr.displayState()
    game_chrctr.recoverState(memento)
    game_chrctr.displayState()
