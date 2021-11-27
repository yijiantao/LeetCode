#include <stdio.h>
#include <pthread.h>
/*
    定义一个pthread_create函数的弱引用，然后在程序运行时动态是否链接到pthread库从而
    决定执行多线程版本还是单线程版本。

    编译运行结果如下：
    $ gcc weak_strong_syb.c -o pt
    $ ./pt
    This is single-thread version!

    $ gcc weak_strong_syb.c -lpthread -o pt
    $ ./pt
    This is multi-thread version!
*/

int pthread_create(
    pthread_t*,
    const pthread_attr_t*,
    void* (*)(void*),
    void*) __attribute__ ((weak));

int main()
{
    if (pthread_create) {
        printf("This is multi-thread version!\n");
        // run the multi-thread version
        // main_multi_thread()
    } else {
        printf("This is single-thread version!\n");
        // run the single-thread version
        // main_single_thread()
    }
}