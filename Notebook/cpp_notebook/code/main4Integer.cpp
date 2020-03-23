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
}