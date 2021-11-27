```shell
gcc -c SimpleSection.c  # -c 表示只编译不链接

objdump -h SimpleSection.o  # 查看目标文件的结构和内容

size SimpleSection.o  # size命令用来查看ELF文件的代码段、数据段和BSS段的长度

objdump -s -d SimpleSection.o  # -s: 参数将所有段的内容以十六进制的方式打印; -d: 包含指令的段反汇编

readelf -h SimpleSection.o  # 详细查看ELF文件

readelf -S SimpleSection.o  # 查看ELF文件等段表结构：包含 .code .data .bss .rodata .comment .note.GNU-stack 6个段还有辅助性的段，例如：符号表、字符串表、段名字符串表、重定位表等。

```