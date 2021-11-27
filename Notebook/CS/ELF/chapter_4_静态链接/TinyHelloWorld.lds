// ld scirpt *.lds
/*
    链接指令：
    gcc -c -fno-builtin TinyHelloWorld.c
    ld -static -T TinyHelloWorld.lds -o TinyHelloWorld TinyHelloWorld.o
*/

ENTRY(nomain)       // 指定程序的入口函数为nomain()

SECTIONS            // 链接脚本主体，指定各种输入段到输出段段变换
{
    . = 0x0804800 + SIZEOF_HEADERS;     // 赋值语句，“.”表示当前虚拟地址；设置起始虚拟地址；SIZEOF_HEADERS为输出文件的文件头大小；

    // 下面两条语句为 段转换规则
    tinytext : { *(.text) *(.data) *(.rodata) }    // 所有输入文件中名字为这三个段的依次合并到输出的可执行文件中的一个叫“tinytext”的段中;
    /DISCARD/ : { *(.comment) }                     // 将所有输入文件中名字为{}中的段进行丢弃，不再保存到输出文件中。（p.s. comment段为编译器和系统版本信息只读段）
}