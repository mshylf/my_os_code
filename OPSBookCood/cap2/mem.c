#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
//该函数首先打印进程id与其使用malloc()所创建的地址，之后每一秒打印一次p++

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    // getpid()函数用于获取当前进程的id，它定义在 <unistd.h> 头文件中，返回一个 pid_t 类型的整数
    printf("(%d) memory  address of p: %08x\n", getpid(), (unsigned)p);
    *p = 0;
    while (1)
    {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}