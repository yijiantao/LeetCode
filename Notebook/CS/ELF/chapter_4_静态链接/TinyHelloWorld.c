/*
    执行指令：
    gcc -c -fno-builtin TinyHelloWorld.c
    ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o
    ./TinyHelloWorld
*/

char* str = "Hello World!\n";

void print()
{
    // GCC 内嵌汇编格式
    asm("mov1 $13, %%edx \n\t"          // str字符13字节
        "mov1 $0, %%ecx \n\t"
        "mov1 $0, %%ebx \n\t"
        "mov1 $4, %%eax \n\t"           // eax为调用号
        "int $0x80      \n\t"           // WRITE系统调用通过0x80中断实现
        ::"r"(str):"edx","ecx","ebx");  // ebx ecx edx等通用寄存器用来传递参数
}

void exit()
{
    asm("mov1 $42, %ebx \n\t"
        "mov1 $1, %eax \n\t"
        "int $0x80      \n\t");
}

void nomain()   // 程序入口函数
{
    print();    // 使用了Linux的WRITE系统调用
    exit();     // 结束进程，使用了EXIT系统调用
}