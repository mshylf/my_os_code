//�ú����������л�ȡһ�������������˲���ÿ���ӡһ��

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
//void assert(int expression);
//���Ժ����������ʽ���Ϊ0�������������Ϣ����ִֹ�У��������ִ��
//����ʧ�����"Assertion `���ʽ` failed: �ļ���: �к�"
#include "common.h"

//argc�������в���������
//argv�������в��������飬��һ�������ǳ������������Ĳ������û������
int main(int argc,char *argv[])
{
    //����û���������
    if(argc!=2)
    {
        //stderr��׼�����������ͨ���������������Ϣ��
        fprintf(stderr,"usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while(1)
    {
        //Spin()��common.h�ж��壬����һ��Ŀ�ѭ��
        Spin(1);
        printf("%s\n",str);
    }
    return 0;
}
