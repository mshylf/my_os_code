#include <stdio.h>


//最简问题是将一个盘子移动的问题
//其余问题都是在这个基础上的
void hnt(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("move %d from %c to %c\n",n,a,c);
        return;
    }
    hnt(n-1,a,c,b);
    printf("move %d from %c to %c\n",n,a,c);
    hnt(n-1,b,a,c);
}

int main()
{
    hnt(3,'A','B','C');
    return 0;
}

