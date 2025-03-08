//该函数从命令行获取一个参数，并将此参数每秒打印一次

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
//void assert(int expression);
//断言函数，若表达式结果为0，则输出错误信息并终止执行，真则继续执行
//断言失败输出"Assertion `表达式` failed: 文件名: 行号"
#include "common.h"

//argc：命令行参数的数量
//argv：命令行参数的数组，第一个参数是程序名，后续的参数是用户输入的
int main(int argc,char *argv[])
{
    //检查用户参数输入
    if(argc!=2)
    {
        //stderr标准错误输出流，通常用于输出错误信息。
        fprintf(stderr,"usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while(1)
    {
        //Spin()在common.h中定义，持续一秒的空循环
        Spin(1);
        printf("%s\n",str);
    }
    return 0;
}
