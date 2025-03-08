#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <pthread.h>

// ����������Pthread_create()�����������̣߳�thread����
// ���Խ��߳̿���������������ͬһ�ڴ�ռ������еĺ���������ÿ�ζ��ж���̴߳��ڻ״̬��
// ����������У�ÿ���߳̿�ʼ��һ����Ϊworker()�ĺ��������У��ڸú����У���ֻ�ǵ���һ����������
// ѭ��loops�Ρ�


// volatile��֪����������ֵ�����Գ��򲻿�Ԥ֪�ķ�ʽ�ı䣬��ֹ��������������ض��Ż���
// ��ÿ�����á�conter��ʱ�����ڴ��ж�ȡ��ֵ,������ʹ�û���ĸ���
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
    // atoi ���������� <stdlib.h> ͷ�ļ��У����ַ������н���Ϊһ������
    loops = atoi(argv[1]);
    // pthread_t ���Ͷ����� <pthread.h> ͷ�ļ���,��Ҫ���ڱ�ʾ�̵߳ı�ʶ��
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);

    // ����һ���µ��߳�
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    // �ȴ�ָ���߳̽���������ȡ���̵߳ķ���ֵ��
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    return 0;
}