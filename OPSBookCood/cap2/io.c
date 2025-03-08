#include <stdio.h>
#include <unistd.h> // 引入UNIX标准函数头文件，包含close、write等系统调用声明
#include <assert.h>
#include <fcntl.h>     // 引入文件控制头文件，定义open函数相关标志（如O_WRONLY等）
#include <sys/types.h> // 引入系统类型定义头文件，定义基本系统数据类型（如mode_t等）
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    // 调用open函数：打开/tmp/file文件，模式为只写（O_WRONLY），若文件不存在则创建（O_CREAT），若存在则截断内容（O_TRUNC）；文件权限设为S_IRWXU（用户可读、写、执行）
    assert(fd > -1);
    // 断言检查：确保open成功执行（返回的文件描述符fd应大于-1，失败时返回-1）
    int rc = write(fd, "hello world\n", 13);
    // 调用write函数：向文件描述符fd指向的文件写入"hello world\n"（共13字节，包括换行符），返回实际写入字节数存到rc
    assert(rc == 13);
    // 断言检查：确保write成功写入13字节
    close(fd);
    // 关闭文件描述符fd，释放系统资源
    return 0;
}