#ifndef INTEGER_H
#define INTEGER_H

// 运算符重载
// 我们自己定义的整型类，将整型封装成类，以便实现面向对象的封装
class Integer
{
    public:
        Integer();
        Integer(int value) : _value(value){}

        // 重载+运算符
        Integer operator+(Integer other);

        //返回值输出
        int IntValue(){return _value;}

        virtual ~Integer();

    protected:

    private:
        int _value;    // 实际的整型数字
};

#endif   // INTEGER_H