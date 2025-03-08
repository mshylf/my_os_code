#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <pthread.h>

// 主程序利用Pthread_create()创建了两个线程（thread）。
// 可以将线程看作与其他函数在同一内存空间中运行的函数，并且每次都有多个线程处于活动状态。
// 在这个例子中，每个线程开始在一个名为worker()的函数中运行，在该函数中，它只是递增一个计数器，
// 循环loops次。


// volatile告知编译器变量值可能以程序不可预知的方式改变，禁止编译器对其进行特定优化。
// 在每次引用‘conter’时都从内存中读取其值,而不是使用缓存的副本
volatile int counter = 0;
int loops;

void *worker(void *arg)
{
    int i;
    for (i = 0; i < loops; i++)
    {
        counter++;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: threads <value>\n");
        exit(1);
    }
    // atoi 函数定义在 <stdlib.h> 头文件中，将字符串序列解析为一个整数
    loops = atoi(argv[1]);
    // pthread_t 类型定义在 <pthread.h> 头文件中,主要用于表示线程的标识符
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);

    // 创建一个新的线程
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    // 等待指定线程结束，并获取该线程的返回值。
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    return 0;
}