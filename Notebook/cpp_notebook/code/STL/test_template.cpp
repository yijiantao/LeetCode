
template <typename T>
T add (const T lva, const T rva)
{
    T a;
    a = lva + rva;
    return a;
}
/*
这是一个模板函数的简单实例，所有模板函数在开始都需要 template 语句，以告诉编译器这是一个模板和参数等必要信息，当然里面的 T 可以取任意你喜欢的名字 ，模板参数个数也是任意更换的。 还要提醒的一点是：template <typename T1 ,typename T2 = int>函数模板是支持默认参数的，T1 、T2 顺序在默认情况下是可以任意的，不用严格按照从右到左的顺序。

然后就是使用了，我们可以写出add(1,2) 这样的函数,也可以写出add(2.5,4.6)这样的函数，向 add 函数提供参数时，编译器会自动分析参数的类型，然后将所有用到 T 定义的换成相对性的类型，以上的两个函数在编译期间会生成
*/

int add(const int lva ,const int rva)
{

    int a ;

    a = lva + rva ;

return a;
}

double add(const double lva ,const double rva)
{

    double a ;

     a = lva + rva ;

return a;
}