```shell
gcc -c SimpleSection.c  # -c 表示只编译不链接

objdump -h SimpleSection.o  # 查看目标文件的结构和内容

size SimpleSection.o  # size命令用来查看ELF文件的代码段、数据段和BSS段的长度

objdump -s -d SimpleSection.o  # -s: 参数将所有段的内容以十六进制的方式打印; -d: 包含指令的段反汇编



```