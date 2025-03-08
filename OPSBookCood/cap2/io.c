#include <stdio.h>
#include <unistd.h> // ����UNIX��׼����ͷ�ļ�������close��write��ϵͳ��������
#include <assert.h>
#include <fcntl.h>     // �����ļ�����ͷ�ļ�������open������ر�־����O_WRONLY�ȣ�
#include <sys/types.h> // ����ϵͳ���Ͷ���ͷ�ļ����������ϵͳ�������ͣ���mode_t�ȣ�
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    // ����open��������/tmp/file�ļ���ģʽΪֻд��O_WRONLY�������ļ��������򴴽���O_CREAT������������ض����ݣ�O_TRUNC�����ļ�Ȩ����ΪS_IRWXU���û��ɶ���д��ִ�У�
    assert(fd > -1);
    // ���Լ�飺ȷ��open�ɹ�ִ�У����ص��ļ�������fdӦ����-1��ʧ��ʱ����-1��
    int rc = write(fd, "hello world\n", 13);
    // ����write���������ļ�������fdָ����ļ�д��"hello world\n"����13�ֽڣ��������з���������ʵ��д���ֽ����浽rc
    assert(rc == 13);
    // ���Լ�飺ȷ��write�ɹ�д��13�ֽ�
    close(fd);
    // �ر��ļ�������fd���ͷ�ϵͳ��Դ
    return 0;
}