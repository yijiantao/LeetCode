#include "Integer.h"

Integer::Integer() : _value(0)    // 调用默认构造时，会为私有成员变量 _value 初始化赋值为 0
{

}

// 重载+运算符
Integer Integer::operator+(Integer other){
    Integer result(this->_value + other._value);    // 用来返回的结果对象
    return result;
}

Integer::~Integer()
{

}