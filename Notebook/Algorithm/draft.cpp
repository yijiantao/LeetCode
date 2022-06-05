#include <iostream>

int i = 42;

// 枚举类型
enum week {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};
//枚举常量Sun,Mon,Tue,Wed,Thu,Fri,Sat的值分别为7、1、2、3、4、5、6。

struct sales_data {
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string date {"year", "month", "day"};
};

int main()
{
    int arr[3] = {1,2,3};
    std::string s (5, 'y');
    std::string y {"yi", "jiantao"};
    std::cout << arr<< std::endl;
    std::cout << s<< std::endl;
    std::cout << y<< std::endl;

    // -*-*-*-*-*-*-*- 变量声明和定义的关系 -*-*-*-*-*-*-*-*
    /*
        为了支持分离式编译，C++语言将声明和定义区分开来。
        声明(declaration）使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。
        而定义(definition）负责创建与名字关联的实体。变量声明规定了变量的类型和名字，在这一点上定义与之相同。
        但是除此之外，定义还申请存储空间，也可能会为变量赋一个初始值。
    如果想声明一个变量而非定义它，就在变量名前添加关键字 extern，而且不要显式地初始化变量：
    */
    extern int i;   // 声明i而非定义i
    int j_1;   // 声明并定义j_1
    

    /* 任何包含了显式初始化的声明即成为定义。
    我们能给由 extern 关键字标记的变量赋一个初始值，但是这么做也就抵消了 extern 的作用。
    extern 语句如果包含初始值就不再是声明，而变成定义了：
        extern double pi = 3.1416; //定义，但不能在函数体内部，在函数体内部，如果试图初始化一个由 extern 关键字标记的变量，将引发错误。
    【Note】: 变量能且只能被定义一次，但是可以被多次声明。
    声明和定义的区别看起来也许微不足道，但实际上却非常重要。如果要在多个文件中使用同一个变量，就必须将声明和定义分离。
    此时，变量的定义必须出现在且只能出现在一个文件中，而其他用到该变量的文件必须对其进行声明，却绝对不能重复定义。
    */

    // -*-*-*-*-*-*-*-*-*- 引用 -*-*-*-*-*-*-*-*
    int i_1 = 100;
    int j = i_1;
    std::cout << i_1 << "and" << j << std::endl;
    int &refj = j; // refj指向j; (refj是j的别名) 且引用类型必须是一个对象（引用只能绑定在对象上），不能给引用赋值；
    // 错误 int &refj = 1;
    std::cout << refj << std::endl;
    refj = 3;
    std::cout << refj << " " << j << std::endl;
    int a, &ri = a;
    a = 5, ri = 10;
    std::cout << a << " " << ri << std::endl;

    // -*-*-*-*-*-*-*-*-* 指针 -*-*-*-*-*-*-*-*
    int ival = 42;
    int *p = &ival;
    std::cout << p << " " << *p << std::endl;    // 解引用符（操作符*）来访问p所指的对象，输出42
    *p = 0;    // *p 赋值实际上是为p所指的对象（ival）赋值
    std::cout << ival << " " << p << " " << *p << std::endl;
    // 空指针
    int *p1 = nullptr;  // 等价于 int *p1 = 0;
    // 先定义对象，再定义指向该对象的指针，做到初始化所有的指针，谨防空指针

    // 枚举类型值输出
    // week w;
    std::cout<< Sun << Fri << std::endl;
    return 0;
}
