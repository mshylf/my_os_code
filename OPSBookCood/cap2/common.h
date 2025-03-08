#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    //声明了一个timeval类型t
    //struct timeval {
    //time_t      tv_sec;     // 秒
    //suseconds_t tv_usec;    // 微秒
    //};
    struct timeval t;
    //调用 gettimeofday 函数获取当前时间
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    //将微妙转化为秒，并加上当前秒数返回
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

//将持续一秒的空循环
void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__
