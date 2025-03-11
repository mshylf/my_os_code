#include <stdio.h>
// f(n)={ 1                n<=2
//        f(n-1) + f(n-2)  n>2
//      }

#define n 7

int fun(int i)
// 会重复计算很多遍，二叉树型结构
{
    if (i <= 2)
        return 1;
    return fun(i - 1) + fun(i - 2);
}


// 记忆化搜索，将计算过的值记录在数组中
int save[n + 1];
void init_save() {
    for (int i = 0; i <= n; i++) {
        save[i] = -1;
    }
}

int fun2(int i)
{
    if (i <= 2)
        return 1;
    if (save[i] == -1)
    {
        save[i] = fun2(i - 1) + fun2(i - 2);
    }
    return save[i];
}

int main()
{
    init_save(); // 初始化 save 数组
    printf("%d\n", fun(n));
    printf("%d\n", fun2(n));
    return 0;
}