#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    //������һ��timeval����t
    //struct timeval {
    //time_t      tv_sec;     // ��
    //suseconds_t tv_usec;    // ΢��
    //};
    struct timeval t;
    //���� gettimeofday ������ȡ��ǰʱ��
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    //��΢��ת��Ϊ�룬�����ϵ�ǰ��������
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

//������һ��Ŀ�ѭ��
void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__
