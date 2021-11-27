## 静态链接指令

```shell
gcc -c a.c b.c  # 分别编译成目标文件“a.o”和“b.o”


# -e main 表示将main函数作为程序入口，ld链接器默认的程序入口为_start
# -o ab 表示链接输出文件名为ab，默认为a.out
ld a.o b.o -e main -o ab    # 使用链接器ld 将 “a.o”和“b.o”链接起来；


objdump -h a.o  # 链接前后文件各个段的属性
objdump -h b.o
objdump -h ab


objdump -d a.o  # -d 参数可以看到 a.o的代码段反汇编结果
objdump -d ab


objdump -r a.o  # 查看目标文件的重定位表
readelf -s a.o  # 查看“a.o”的符号表


ar -t libc.a    # 使用“ar”工具来查看这个文件包含哪些目标文件
objdump -t libc.a   # 查看libc.a的符号


# 默认为动态链接；使用 -static参数指定ld将使用静态链接的方式来链接程序
gcc -static --verbose a.c  # "-verbose"表示将整个编译链接过程的中间步骤打印出来；


# 4.6.1、链接控制脚本
ld -verbose             # 查看ld默认的链接脚本
ld -T diy_link.script   # 使用 -T 参数指定该脚本为链接过程控制脚本

```