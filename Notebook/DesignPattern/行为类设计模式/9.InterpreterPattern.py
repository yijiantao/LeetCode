# -*- coding: UTF-8 -*-
"""
    一、定义：
        解释器模式定义如下：
        给定一种语言，定义它的文法表示，并定义一个解释器，该解释器使用该表示来解释语言中的句子。
        典型的解释器模式中会有终结符和非终结符之说，语法也根据两种终结符，决定语句最终含义。
        上例中，非终结符就是空格，终结符就是整个句尾。
    
    二、场景：
        开发一个自动识别谱子的吉他模拟器，达到录入谱即可按照谱发声的效果。
        除了发声设备外（假设已完成），最重要的就是读谱和译谱能力了。
        分析其需求，整个过程大致上分可以分为两部分：根据规则翻译谱的内容；根据翻译的内容演奏。我们用一个解释器模型来完成这个功能。
"""


class PlayContext():    # 定义 演奏（曲谱）内容类
    play_text = None


class Expression():

    # Expression即表达式，里面仅含两个方法，interpret负责转译谱，execute则负责演奏

    def interpret(self, context):
        if len(context.play_text) == 0:
            return
        else:
            play_segs = context.play_text.split(" ")
            for play_seg in play_segs:
                pos = 0
                for ele in play_seg:
                    if ele.isalpha():
                        pos += 1
                        continue
                    break
                play_chord = play_seg[0:pos]
                play_value = play_seg[pos:]
                self.execute(play_chord, play_value)

    def execute(self, play_key, play_value):
        pass


class NormGuitar(Expression):

    # NormGuitar类覆写execute，以吉他 的方式演奏

    def execute(self, key, value):
        print ("Normal Guitar Playing--Chord:%s Play Tune:%s" % (key, value))


if __name__ == "__main__":
    """
        业务场景：以吉他的方式演奏。
    """
    context = PlayContext()
    context.play_text = "C53231323 Em43231323 F43231323 G63231323"
    guitar = NormGuitar()
    guitar.interpret(context)
