#include<iostream>
#include "Integer.cpp"

using namespace std;

void TestInteger();

int main(int argc, char const *argv[])
{
    TestInteger();
    return 0;
}

void TestInteger(){
    Integer int1(1024), int2(2048), int3;
    int3 = int1 + int2;
    cout << "int3 = int1 + int2的结果为：" << int3.IntValue() << endl;
    int3 = int1 - int2;
    cout << "int3 = int1 - int2的结果为：" << int3.IntValue() << endl;

    // 运算符 = 重载
    Integer int4;
    int4 = int3;
    cout << "int4: " << int4.IntValue() << endl;

    // 友元函数重载*运算符
    Integer int5 = 10 * int4;
    cout << "int5 = " << int5.IntValue() << endl;

    cout << "重载了<<运算符后，可以直接打印对象：int5 = " << int5 << endl;

    Integer int6;
    cin >> int6;
    cout << "输入的int6为：" << int6 << endl;
}