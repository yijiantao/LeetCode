
## ELF文件结构中“Section”和“Segment”的区别

很明显，所有相同属性的“Section”被归类到一个“Segment”，并且映射到同一个 VMA。虚拟内存区域（VMA，Virtual Memory Area）；

ELF 可执行文件引入了一个概念叫做 “Segment”，一个“Segment” 包含一个或多个属性类似的“Section”。
正如我们上面的例子中看到的，如果将“.text”段和“init” 段合并在
一起看作是一个“Segment”，那么装载的时候就可以将它们看作一个整体一起映射，也就是
说映射以后在进程虚存空间中只有一个相对应的 VMA，而不是两个，这样做的好处是可以
很明显地减少页面内部碎片，从而节省了内存空间。

很难将 "Segment” 和"Section"这两个词从中文的翻译上加以区分，因为很多时候 Section 也被翻译成“段”，回顾第2章，我们也没有很严格区分这两个英文词汇和两个中文词汇 “段”和“节”之问的相互翻译。很明显：
从链接的角度看，ELF 文件是按"Section"存储的，事实也的确如此；
从装载的角度看，ELF 文件又可以按照"Segment"划分。
我们在这里就对"Segment” 不作翻译，一律按照原词。


我们可以使用readelf 命令来查看 ELF的“Segment”。
正如描述“Section”属性的结构叫做段表，描述“Segment” 的结构叫程序头 (Program Header)，它描述了 ELF 文件该如
何被操作系统映射到进程的虚拟空间：
$ readelf -l SectionMapping.elf


```bash
# 静态链接
gcc -static SectionMapping.c -o SectionMapping.elf

readelf -S SectionMapping.elf    # 查看可执行文件中总共有33个段（Section）

readelf -l SectionMapping.elf


```