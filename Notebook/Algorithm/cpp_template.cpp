#include <iostream>

/*
    面向对象编程（OOP）和泛型编程都能处理在编写程序时不知道类型的情况。
    不同之处在于：
    OOP能处理类型在程序运行之前都未知的情况，而在泛型编程中，在编译时就能获知类型了。
*/

template <typename T>
int compare(const T &v1, const T &v2)
{
    return v1 > v2 ? v1 : v2;
}

int main()
{
    // 1、定义模板

    // 2、模板实参推断

    // 3、

    // 4、

    // 5、
    
    return 0;
}