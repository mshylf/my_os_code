#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
//�ú������ȴ�ӡ����id����ʹ��malloc()�������ĵ�ַ��֮��ÿһ���ӡһ��p++

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    // getpid()�������ڻ�ȡ��ǰ���̵�id���������� <unistd.h> ͷ�ļ��У�����һ�� pid_t ���͵�����
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