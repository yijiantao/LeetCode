#include<bits/stdc++.h>
using namespace std;

void Swap1(int, int);    // 函数原型 定义；
void Swap2(int*, int*);
void Swap3(int&, int&);    // 三个Swap函数用于举例说明：使用引用参数
string Show(const int&, const int&);    // 参数的引用传递时， 形参加 const，防止在函数内部修改变量值

int& sum(int& num1, int& num2)
{
    // 理解 函数返回引用类型, 当无返回值时，默认返回传入的引用对象本身
    num1 ++;
    num2 ++;
    
}

int main(){
    /*
        8位 = 1字节    // 位：位表示有几位二进制数字。
        8bit=1byte // 10101010
        整型是32位/4字节。
    */

   char ch = 'a';
   char * ptr_ch = &ch;

   cout << "指针取址为：" << ptr_ch << '\t' << (char *)ptr_ch << '\t' << (void *)ptr_ch << endl;
   cout << "指针取值为：" << *ptr_ch << endl;

   double num = 3.14;
   double * ptr_num = &num;

   cout << "指针取址为：" << ptr_num << endl;
   cout << "指针取值为：" << *ptr_num << endl;

   double * ptr_double = nullptr;    // 赋初值 空指针，避免野指针 double * ptr_double;
   cout << ptr_double << endl;

    
    cout << 10.0 / 3.0 * 10000 << endl;
    cout << fixed;   // 转换 cout 固定输出小数格式，非科学计数法输出
    cout << 10.0 / 3.0 * 10000 << endl;
    cout << setprecision(2);    // 输出小数点后 2位
    cout << 10.0 / 3.0 * 10000 << endl;
    cout.setf(ios_base::floatfield);    // 等效于如上两个子语句：cout << fixed << setprecision(2)
    
    printf("Hello\n");
    string a = "yijiantao";
    char b[100] = "yijiantao";
    /* string 字符串所占的空间是从堆中动态分配的，与sizeof()无关!!! 
       sizeof(string)=4可能是最典型的实现之一，不过也有sizeof()为12、32字节的库实现。 
       但是MS2015测试后sizeof(string)=40.还是跟编译器有关，
       也就是说sizeof(string)和字符串的长度是无关的，在一个系统中所有的sizeof(string)是一个固定值，这个和编译器相关，
       string字符串是存储在堆上，这个属于动态分配的空间.
     
    */
    cout << "sizeof a:" << sizeof(a) << endl;
    cout << "sizeof b:" << sizeof(b) << endl;
    cout << "strlen:" << strlen(b) << endl;
    cout << "size:" << a.size() << endl;
    cout << "length:" << a.length() << endl;

    for (int _row = 1; _row < 9; ++_row){
        for (int _col = 1; _col <= _row; ++_col){
            // cout<<_row<<"*"<<_col<<"="<<_row*_col<<" ";
            printf("%d*%d=%d ", _row, _col, _row*_col);
        }
        printf("\n");
        // cout<<endl;
    }

    // 动态分配内存
    int num_arr[5];    // 编译时
    int* nums = new int[5];    // 运行时,nums指针在栈内存中，new int[5]在堆内存中；
    cout << sizeof(num_arr) << '\t' << sizeof(nums) << endl;

    // 参数的引用传递 代码示例
    int num1, num2;
    num1 = 10, num2 = 5;
    Swap1(num1, num2);
    cout << "Swap1执行结果为: " << Show(num1, num2) << endl;

    num1 = 10, num2 = 5;
    Swap2(&num1, &num2);
    cout << "Swap2执行结果为: " << Show(num1, num2) << endl;

    num1 = 10, num2 = 5;
    Swap3(num1, num2);
    cout << "Swap3执行结果为: " << Show(num1, num2) << endl;

    // 函数可以不返回值，默认返回传入的引用对象本身，最后一个变量的值；
    num1 = 10, num2 = 5;
    cout << sum(num1, num2) << endl;

}

void Swap1(int num1, int num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void Swap2(int* p1, int* p2)
{
    // 交换地址，而非值
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Swap3(int& ref1, int& ref2)
{
    /*
        使用引用的理由
        1、可以更加简便的书写代码；
        2、可以直接传递某个对象，而不只是把对象复制一份；
    */
    int temp;
    temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
string Show(const int& num1, const int& num2)
{
    /*
        我们希望显示函数中，只能实现传入参数的显示功能
        而禁止显示函数中修改num1和num2的值（禁止函数内部修改引用参数值）
        解决方案：在参数中使用const
    */
   // num1 = 1024;    // 修改形参时，编译报错，不允许
   return to_string(num1) + "\t" + to_string(num2);
}
