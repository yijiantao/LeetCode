## Linux中用gdb 查看代码堆栈的信息

&emsp;&emsp;core dump 一般是在segmentation fault（段错误）的情况下产生的文件，需要通过ulimit来设置才会得到的。

&emsp;&emsp;调试的话输入： gdb filename core

&emsp;&emsp;其中，filename就是产生core文件的可执行文件，core就是产生的dump文件

## 一、查看栈信息
&emsp;&emsp;当程序被停住了，你需要做的第一件事就是查看程序是在哪里停住的。当你的程序调用了一个函数，函数的地址，函数参数，函数内的局部变量都会被压入“栈”（Stack）中。你可以用GDB命令来查看当前的栈中的信息。

&emsp;&emsp;下面是一些查看函数调用栈信息的GDB命令：
> backtrace/bt

&emsp;&emsp;打印当前的函数调用栈的所有信息。如：
```bash
(gdb) bt
#0 func (n=250) at tst.c:6
#1 0x08048524 in main (argc=1, argv=0xbffff674) at tst.c:30
#2 0x400409ed in __libc_start_main () from /lib/libc.so.6
```

&emsp;&emsp;从上可以看出函数的调用栈信息：__libc_start_main --> main()--> func()

```bash
backtrace
(bt)
n是一个正整数，表示只打印栈顶上n层的栈信息。

backtrace <-n>

bt <-n>

-n表一个负整数，表示只打印栈底下n层的栈信息。
```

&emsp;&emsp;如果你要查看某一层的信息，你需要在切换当前的栈，一般来说，程序停止时，最顶层的栈就是当前栈，如果你要查看栈下面层的详细信息，首先要做的是切换当前栈。

```bash
frame
f
n是一个从0开始的整数，是栈中的层编号。比如：frame 0，表示栈顶，frame 1，表示栈的第二层。

up
表示向栈的上面移动n层，可以不打n，表示向上移动一层。

down
表示向栈的下面移动n层，可以不打n，表示向下移动一层。

上面的命令，都会打印出移动到的栈层的信息。如果你不想让其打出信息。你可以使用这三个命令：

select-frame 对应于 frame 命令。
up-silently 对应于 up 命令。
down-silently 对应于 down 命令。
```


&emsp;&emsp;查看当前栈层的信息，你可以用以下GDB命令：
```bash
frame 或 f
会打印出这些信息：栈的层编号，当前的函数名，函数参数值，函数所在文件及行号，函数执行到的语句。

info frame

info f

这个命令会打印出更为详细的当前栈层的信息，只不过，大多数都是运行时的内内
地址。比如：函数地址，调用函数的地址，被调用函数的地址，目前的函数是由什么
样的程序语言写成的、函数参数地址及值、局部变量的地址等等。如：
```

```bash
(gdb) info f
Stack level 0, frame at 0xbffff5d4:
eip = 0x804845d in func (tst.c:6); saved eip 0x8048524
called by frame at 0xbffff60c
source language c.
Arglist at 0xbffff5d4, args: n=250
Locals at 0xbffff5d4, Previous frame's sp is 0x0
Saved registers:
ebp at 0xbffff5d4, eip at 0xbffff5d8
```

> info args  
打印出当前函数的参数名及其值。

> info locals  
打印出当前函数中所有局部变量及其值。

> info catch  
打印出当前的函数中的异常处理信息。


## 二、查看源程序

### 2.1、显示源代码

&emsp;&emsp;GDB 可以打印出所调试程序的源代码，当然，在程序编译时一定要加上-g的参数，把源程序信息编译到执行文件中。不然就看不到源程序了。当程序停下来以后，GDB会报告程序停在了那个文件的第几行上。你可以用list命令来打印程序的源代码。还是来看一看查看源代码的GDB命令吧。

```bash
list
显示程序第linenum行的周围的源程序。

list
显示函数名为function的函数的源程序。

list
显示当前行后面的源程序。

list -
显示当前行前面的源程序。
```

&emsp;&emsp;一般是打印当前行的上5行和下5行，如果显示函数是是上2行下8行，默认是10行，当然，你也可以定制显示的范围，使用下面命令可以设置一次显示源程序的行数。
```bash
set listsize
设置一次显示源代码的行数。

show listsize
查看当前listsize的设置。

list命令还有下面的用法：

list ,
显示从first行到last行之间的源代码。

list ,
显示从当前行到last行之间的源代码。

list +
往后显示源代码。
```

&emsp;&emsp;一般来说在list后面可以跟以下这们的参数：
```bash
行号。
<+offset> 当前行号的正偏移量。
<-offset> 当前行号的负偏移量。
哪个文件的哪一行。
函数名。
哪个文件中的哪个函数。
<*address> 程序运行时的语句在内存中的地址。
```

### 2.2、搜索源代码

不仅如此，GDB还提供了源代码搜索的命令：

forward-search
search
向前面搜索。

reverse-search
全部搜索。

其中，就是正则表达式，也主一个字符串的匹配模式，关于正则表达式，我就不在这里讲了，还请各位查看相关资料。


### 2.3、指定源文件的路径

&emsp;&emsp;某些时候，用-g编译过后的执行程序中只是包括了源文件的名字，没有路径名。GDB提供了可以让你指定源文件的路径的命令，以便GDB进行搜索。
directory
dir
加一个源文件路径到当前路径的前面。如果你要指定多个路径，UNIX下你可以使用“:”，Windows下你可以使用“;”。
directory
清除所有的自定义的源文件搜索路径信息。

show directories
显示定义了的源文件搜索路径。

### 2.4、源代码的内存

&emsp;&emsp;你可以使用info line命令来查看源代码在内存中的地址。info line后面可以跟“行号”，“函数名”，“文件名:行号”，“文件名:函数名”，这个命令会打印出所指定的源码在运行时的内存地址，如：

```bash
(gdb) info line tst.c:func
Line 5 of "tst.c" starts at address 0x8048456 and ends at 0x804845d.
```

&emsp;&emsp;还有一个命令（disassemble）你可以查看源程序的当前执行时的机器码，这个命令会把目前内存中的指令dump出来。如下面的示例表示查看函数func的汇编代码。

```bash
(gdb) disassemble func
Dump of assembler code for function func:
0x8048450 : push %ebp
0x8048451 : mov %esp,%ebp
0x8048453 : sub $0x18,%esp
0x8048456 : movl $0x0,0xfffffffc(%ebp)
0x804845d : movl $0x1,0xfffffff8(%ebp)
0x8048464 : mov 0xfffffff8(%ebp),%eax
0x8048467 : cmp 0x8(%ebp),%eax
0x804846a : jle 0x8048470
0x804846c : jmp 0x8048480
0x804846e : mov %esi,%esi
0x8048470 : mov 0xfffffff8(%ebp),%eax
0x8048473 : add %eax,0xfffffffc(%ebp)
0x8048476 : incl 0xfffffff8(%ebp)
0x8048479 : jmp 0x8048464
0x804847b : nop
0x804847c : lea 0x0(%esi,1),%esi
0x8048480 : mov 0xfffffffc(%ebp),%edx
0x8048483 : mov %edx,%eax
0x8048485 : jmp 0x8048487
0x8048487 : mov %ebp,%esp
0x8048489 : pop %ebp
0x804848a : ret
End of assembler dump.
```

## 三、查看运行时数据
&emsp;&emsp;在你调试程序时，当程序被停住时，你可以使用print命令（简写命令为p），或是同义命令inspect来查看当前程序的运行数据。print命令的格式是：

print
print /
是表达式，是你所调试的程序的语言的表达式（GDB可以调试多种编程语言），是输出的格式，比如，如果要把表达式按16进制的格式输出，那么就是/x。


### 3.1、表达式

&emsp;&emsp;print和许多GDB的命令一样，可以接受一个表达式，GDB会根据当前的程序运行的数据来计算这个表达式，既然是表达式，那么就可以是当前程序运行中的const常量、变量、函数等内容。可惜的是GDB不能使用你在程序中所定义的宏。

&emsp;&emsp;表达式的语法应该是当前所调试的语言的语法，由于C/C++是一种大众型的语言，所以，本文中的例子都是关于C/C++的。（而关于用GDB调试其它语言的章节，我将在后面介绍）

&emsp;&emsp;在表达式中，有几种GDB所支持的操作符，它们可以用在任何一种语言中。
```bash
@
是一个和数组有关的操作符，在后面会有更详细的说明。

::
指定一个在文件或是一个函数中的变量。

{}
表示一个指向内存地址的类型为type的一个对象。
```


### 3.2、程序变量

&emsp;&emsp;在GDB中，你可以随时查看以下三种变量的值：
- 1、全局变量（所有文件可见的）
- 2、静态全局变量（当前文件可见的）
- 3、局部变量（当前Scope可见的）

&emsp;&emsp;如果你的局部变量和全局变量发生冲突（也就是重名），一般情况下是局部变量会隐藏全局变量，也就是说，如果一个全局变量和一个函数中的局部变量同名时，如果当前停止点在函数中，用print显示出的变量的值会是函数中的局部变量的值。如果此时你想查看全局变量的值时，你可以使用“::”操作符：

```bash
file::variable
function::variable
可以通过这种形式指定你所想查看的变量，是哪个文件中的或是哪个函数中的。例如，查看文件f2.c中的全局变量x的值：

(gdb) p 'f2.c'::x

当然，“::”操作符会和C++中的发生冲突，GDB能自动识别“::”是否C++的操作符，所以你不必担心在调试C++程序时会出现异常。
```

&emsp;&emsp;另外，需要注意的是，如果你的程序编译时开启了优化选项，那么在用GDB调试被优化过的程序时，可能会发生某些变量不能访问，或是取值错误码的情况。这个是很正常的，因为优化程序会删改你的程序，整理你程序的语句顺序，剔除一些无意义的
变量等，所以在GDB调试这种程序时，运行时的指令和你所编写指令就有不一样，也
就会出现你所想象不到的结果。对付这种情况时，需要在编译程序时关闭编译优化。
一般来说，几乎所有的编译器都支持编译优化的开关，例如，GNU 的C/C++编译器
GCC，你可以使用“-gstabs”选项来解决这个问题。关于编译器的参数，还请查看编
译器的使用说明文档。

### 3.3、数组

&emsp;&emsp;有时候，你需要查看一段连续的内存空间的值。比如数组的一段，或是动态分配的数据的大小。你可以使用GDB的“@”操作符，“@”的左边是第一个内存的地址的
值，“@”的右边则你你想查看内存的长度。例如，你的程序中有这样的语句：
```C
int *array = (int *) malloc (len * sizeof (int));
```

&emsp;&emsp;于是，在GDB调试过程中，你可以以如下命令显示出这个动态数组的取值：
```C
p *array@len
```

&emsp;&emsp;@的左边是数组的首地址的值，也就是变量array所指向的内容，右边则是数据的长度，其保存在变量len中，其输出结果，大约是下面这个样子的：
```bash
(gdb) p *array@len
$1 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,34, 36, 38, 40}
```

&emsp;&emsp;如果是静态数组的话，可以直接用print数组名，就可以显示数组中所有数据的内容了。


### 3.4、输出格式

&emsp;&emsp;一般来说，GDB会根据变量的类型输出变量的值。但你也可以自定义GDB的输出的格式。例如，你想输出一个整数的十六进制，或是二进制来查看这个整型变量的中的
位的情况。要做到这样，你可以使用GDB的数据显示格式：

x 按十六进制格式显示变量。
d 按十进制格式显示变量。
u 按十六进制格式显示无符号整型。
o 按八进制格式显示变量。
t 按二进制格式显示变量。
a 按十六进制格式显示变量。
c 按字符格式显示变量。
f 按浮点数格式显示变量。

```bash
(gdb) p i
$21 = 101

(gdb) p/a i
$22 = 0x65

(gdb) p/c i
$23 = 101 'e'

(gdb) p/f i
$24 = 1.41531145e-43

(gdb) p/x i
$25 = 0x65

(gdb) p/t i
$26 = 1100101
```

### 3.5、查看内存

&emsp;&emsp;你可以使用examine命令（简写是x）来查看内存地址中的值。x命令的语法如下所示：
```bash
x/

n、f、u是可选的参数。
```

n 是一个正整数，表示显示内存的长度，也就是说从当前地址向后显示几个地址的内容。
f 表示显示的格式，参见上面。如果地址所指的是字符串，那么格式可以是s，如果地十是指令地址，那么格式可以是i。
u 表示从当前地址往后请求的字节数，如果不指定的话，GDB默认是4个bytes。
 
u参数可以用下面的字符来代替，b表示单字节，h表示双字节，w表示四字节，g表示八字节。

&emsp;&emsp;当我们指定了字节长度后，GDB会从指内存定的内存地址开始，读写指定字节，并把其当作一个值取出来。

&emsp;&emsp;表示一个内存地址。

n/f/u三个参数可以一起使用。例如：

命令：x/3uh 0x54320表示，从内存地址0x54320读取内容，h表示以双字节为一个单位，3表示三个单位，u表示按十六进制显示。


### 3.6、自动显示

&emsp;&emsp;你可以设置一些自动显示的变量，当程序停住时，或是在你单步跟踪时，这些变量会自动显示。相关的GDB命令是display。

```bash
display
display/
display/
```

expr是一个表达式，fmt表示显示的格式，addr表示内存地址，当你用display设定好了一个或多个表达式后，只要你的程序被停下来，GDB会自动显示你所设置的这些表达式的值。

格式i和s同样被display支持，一个非常有用的命令是：
```bash
display/i $pc
```

$pc是GDB的环境变量，表示着指令的地址，/i则表示输出格式为机器指令码，也就是汇编。于是当程序停下后，就会出现源代码和机器指令码相对应的情形，这是一个很有意思的功能。

下面是一些和display相关的GDB命令：

undisplay
delete display
删除自动显示，dnums意为所设置好了的自动显式的编号。如果要同时删除几个，编号可以用空格分隔，如果要删除一个范围内的编号，可以用减号表示（如：2-5）

disable display
enable display
disable和enalbe不删除自动显示的设置，而只是让其失效和恢复。

info display
查看display设置的自动显示的信息。GDB会打出一张表格，向你报告当然调试中设置了多少个自动显示设置，其中包括，设置的编号，表达式，是否enable。

### 3.7、设置显示选项

&emsp;&emsp;GDB中关于显示的选项比较多，这里我只例举大多数常用的选项。
- set print address
- set print address on
  
&emsp;&emsp;打开地址输出，当程序显示函数信息时，GDB会显出函数的参数地址。系统默认为打开的，如：
```bash
(gdb) f
#0 set_quotes (lq=0x34c78 "<<",rq=0x34c88 ">>")
at input.c:530
530 if (lquote != def_lquote)


set print address off
关闭函数的参数地址显示，如：

(gdb) set print addr off
(gdb) f
#0 set_quotes (lq="<<",rq=">>") at input.c:530
530 if (lquote != def_lquote)

show print address
查看当前地址显示选项是否打开。

set print array
set print array on
打开数组显示，打开后当数组显示时，每个元素占一行，如果不打开的话，每个元素则以逗号分隔。这个选项默认是关闭的。与之相关的两个命令如下，我就不再多说了。

set print array off
show print array

set print elements
这个选项主要是设置数组的，如果你的数组太大了，那么就可以指定一个来指定数据显示的最大长度，当到达这个长度时，GDB就不再往下显示了。如果设置为0，则表示不限制。

show print elements
查看print elements的选项信息。

set print null-stop
如果打开了这个选项，那么当显示字符串时，遇到结束符则停止显示。这个选项默认为off。

set print pretty on
如果打开printf pretty这个选项，那么当GDB显示结构体时会比较漂亮。如：

$1 = {
next = 0x0,
flags = {
sweet = 1,
sour = 1
},
meat = 0x54 "Pork"
}

set print pretty off
关闭printf pretty这个选项，GDB显示结构体时会如下显示：

$1 = {next = 0x0, flags = {sweet = 1, sour = 1}, meat = 0x54"Pork"}

show print pretty
查看GDB是如何显示结构体的。


set print sevenbit-strings
设置字符显示，是否按“\nnn”的格式显示，如果打开，则字符串或字符数据按\nnn显示，如“\065”。

show print sevenbit-strings
查看字符显示开关是否打开。

set print union
设置显示结构体时，是否显式其内的联合体数据。例如有以下数据结构：

typedef enum {Tree, Bug} Species;
typedef enum {Big_tree, Acorn, Seedling} Tree_forms;
typedef enum {Caterpillar, Cocoon, Butterfly}
Bug_forms;

struct thing {
Species it;
union {
Tree_forms tree;
Bug_forms bug;
} form;
};

struct thing foo = {Tree, {Acorn}};

当打开这个开关时，执行 p foo 命令后，会如下显示：
$1 = {it = Tree, form = {tree = Acorn, bug = Cocoon}}

当关闭这个开关时，执行 p foo 命令后，会如下显示：
$1 = {it = Tree, form = {...}}

show print union
查看联合体数据的显示方式

set print object
在C++中，如果一个对象指针指向其派生类，如果打开这个选项，GDB会自动按照虚方法调用的规则显示输出，如果关闭这个选项的话，GDB就不管虚函数表了。这个选项默认是off。

show print object
查看对象选项的设置。

set print static-members
这个选项表示，当显示一个C++对象中的内容是，是否显示其中的静态数据成员。默认是on。

show print static-members
查看静态数据成员选项设置。

set print vtbl
当此选项打开时，GDB将用比较规整的格式来显示虚函数表时。其默认是关闭的。

show print vtbl
查看虚函数显示格式的选项。
```

### 3.8、历史记录

&emsp;&emsp;当你用GDB的print查看程序运行时的数据时，你每一个print都会被GDB记录下来。
&emsp;&emsp;GDB会以$1, $2, $3 .....这样的方式为你每一个print命令编上号。于是，你可以使用这个编号访问以前的表达式，如$1。这个功能所带来的好处是，如果你先前输入了一个比较长的表达式，如果你还想查看这个表达式的值，你可以使用历史记录
来访问，省去了重复输入。


### 3.9、GDB环境变量

&emsp;&emsp;你可以在GDB的调试环境中定义自己的变量，用来保存一些调试程序中的运行数据。要定义一个GDB的变量很简单只需。使用GDB的set命令。GDB的环境变量和UNIX一样，也是以$起头。如：

> set $foo = *object_ptr

&emsp;&emsp;使用环境变量时，GDB会在你第一次使用时创建这个变量，而在以后的使用中，则直接对其賦值。环境变量没有类型，你可以给环境变量定义任一的类型。包括结构体和数组。

> show convenience  
//该命令查看当前所设置的所有的环境变量。

&emsp;&emsp;这是一个比较强大的功能，环境变量和程序变量的交互使用，将使得程序调试更为灵活便捷。例如：

> set $i = 0
> 
> print bar[$i++]->contents

&emsp;&emsp;于是，当你就不必，print bar[0]->contents, printbar[1]->contents地输入命令了。输入这样的命令后，只用敲回车，重复执行上一条语句，环境变量会自动累加，从而完成逐个输出的功能。


### 3.10、查看寄存器

&emsp;&emsp;要查看寄存器的值，很简单，可以使用如下命令：

> info registers  
//查看寄存器的情况。（除了浮点寄存器）

> info all-registers  
查看所有寄存器的情况。（包括浮点寄存器）

> info registers  
查看所指定的寄存器的情况。

&emsp;&emsp;寄存器中放置了程序运行时的数据，比如程序当前运行的指令地址（ip），程序的当前堆栈地址（sp）等等。你同样可以使用print命令来访问寄存器的情况，只需要在寄存器名字前加一个$符号就可以了。如：p $eip。

## 四、改变程序的执行

&emsp;&emsp;一旦使用GDB挂上被调试程序，当程序运行起来后，你可以根据自己的调试思路来动态地在GDB中更改当前被调试程序的运行线路或是其变量的值，这个强大的功能能够让你更好的调试你的程序，比如，你可以在程序的一次运行中走遍程序的所有分支。


### 4.1、修改变量值

&emsp;&emsp;修改被调试程序运行时的变量值，在GDB中很容易实现，使用GDB的print命令即可完成。如：

```bash
(gdb) print x=4

x=4这个表达式是C/C++的语法，意为把变量x的值修改为4，如果你当前调试的语言是Pascal，那么你可以使用Pascal的语法：x:=4。

在某些时候，很有可能你的变量和GDB中的参数冲突，如：

(gdb) whatis width
type = double
(gdb) p width
$4 = 13
(gdb) set width=47
Invalid syntax in expression.

因为，set width是GDB的命令，所以，出现了“Invalid syntax inexpression”的设置错误，此时，你可以使用setvar命令来告诉GDB，width不是你GDB的参数，而是程序的变量名，如：

(gdb) set var width=47

另外，还可能有些情况，GDB并不报告这种错误，所以保险起见，在你改变程序变量取值时，最好都使用setvar格式的GDB命令。
```

### 4.2、跳转执行

&emsp;&emsp;一般来说，被调试程序会按照程序代码的运行顺序依次执行。GDB提供了乱序执行的功能，也就是说，GDB可以修改程序的执行顺序，可以让程序执行随意跳跃。这个功能可以由GDB的jump命令来完：

jump
指定下一条语句的运行点。可以是文件的行号，可以是file:line格式，可以是+num这种偏移量格式。表式着下一条运行语句从哪里开始。

jump

这里的是代码行的内存地址。

&emsp;&emsp;注意，jump命令不会改变当前的程序栈中的内容，所以，当你从一个函数跳到另一个函数时，当函数运行完返回时进行弹栈操作时必然会发生错误，可能结果还是非常
奇怪的，甚至于产生程序Core Dump。所以最好是同一个函数中进行跳转。

&emsp;&emsp;熟悉汇编的人都知道，程序运行时，有一个寄存器用于保存当前代码所在的内存地址。所以，jump命令也就是改变了这个寄存器中的值。于是，你可以使用“set $pc”来更改跳转执行的地址。如：
```bash
set $pc = 0x485
```


### 4.3、产生信号量

&emsp;&emsp;使用singal命令，可以产生一个信号量给被调试的程序。如：中断信号Ctrl+C。这非常方便于程序的调试，可以在程序运行的任意位置设置断点，并在该断点用GDB产生一个信号量，这种精确地在某处产生信号非常有利程序的调试。

&emsp;&emsp;语法是：signal ，UNIX的系统信号量通常从1到15。所以取值也在这个范围。

&emsp;&emsp;single命令和shell的kill命令不同，系统的kill命令发信号给被调试程序时，是由GDB截获的，而single命令所发出一信号则是直接发给被调试程序的。

### 4.4、强制函数返回

&emsp;&emsp;如果你的调试断点在某个函数中，并还有语句没有执行完。你可以使用return命令强制函数忽略还没有执行的语句并返回。

return
return
&emsp;&emsp;使用return命令取消当前函数的执行，并立即返回，如果指定了，那么该表达式的值会被认作函数的返回值。


### 4.5、强制调用函数
```bash
call
```

&emsp;&emsp;表达式中可以一是函数，以此达到强制调用函数的目的。并显示函数的返回值，如果函数返回值是void，那么就不显示。

&emsp;&emsp;另一个相似的命令也可以完成这一功能——print，print后面可以跟表达式，所以也可以用他来调用函数，print和call的不同是，如果函数返回void，call则不显示，print则显示函数返回值，并把该值存入历史数据中。

## 五、在不同语言中使用GDB

&emsp;&emsp;GDB支持下列语言：C, C++, Fortran, PASCAL, Java, Chill, assembly, 和Modula-2。一般说来，GDB会根据你所调试的程序来确定当然的调试语言，比如：发现文件名后缀为“.c”的，GDB会认为是C程序。文件名后缀为 “.C, .cc, .cp, .cpp, .cxx, .c++”的，GDB会认为是C++程序。而后缀是“.f, .F”的，GDB会认为是Fortran程序，还有，后缀为如果是“.s, .S”的会认为是汇编语言。

&emsp;&emsp;也就是说，GDB会根据你所调试的程序的语言，来设置自己的语言环境，并让GDB的命令跟着语言环境的改变而改变。比如一些GDB命令需要用到表达式或变量时，这些
表达式或变量的语法，完全是根据当前的语言环境而改变的。例如C/C++中对指针
的语法是*p，而在Modula-2中则是p^。并且，如果你当前的程序是由几种不同语言
一同编译成的，那到在调试过程中，GDB也能根据不同的语言自动地切换语言环境。
这种跟着语言环境而改变的功能，真是体贴开发人员的一种设计。


&emsp;&emsp;下面是几个相关于GDB语言环境的命令：

```bash
show language
查看当前的语言环境。如果GDB不能识为你所调试的编程语言，那么，C语言被认为是默认的环境。

info frame
查看当前函数的程序语言。

info source
查看当前文件的程序语言。
```

如果GDB没有检测出当前的程序语言，那么你也可以手动设置当前的程序语言。使用set language命令即可做到。

当set language命令后什么也不跟的话，你可以查看GDB所支持的语言种类：
```bash
(gdb) set language
The currently understood settings are:

local or auto Automatic setting based on source file
c Use the C language
c++ Use the C++ language
asm Use the Asm language
chill Use the Chill language
fortran Use the Fortran language
java Use the Java language
modula-2 Use the Modula-2 language
pascal Use the Pascal language
scheme Use the Scheme language
```

&emsp;&emsp;于是你可以在set language后跟上被列出来的程序语言名，来设置当前的语言环境。
