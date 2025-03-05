//https://www.luogu.com.cn/record/186116303
//免责声明：仅从洛谷复制，本人已通过，只能作为学习使用
//请勿直接CV
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>

void mul(int* a, int* b)
{
    int i, j, res[125];
    memset(res, 0, sizeof(res));
    for (i = 0; i < 125; i++)
        for (j = 0; j < 125 - i; j++)
        {
            res[i + j] += a[i] * b[j];
            res[i + j + 1] += res[i + j] / 10000;
            res[i + j] %= 10000;
        }
    memcpy(a, res, sizeof(res));
}
int p, result[125], base[125];
int main()
{
    int i;
    scanf("%d", &p);
    printf("%d\n", (int)(p * log10(2.0)) + 1);
    result[0] = 1;
    base[0] = 2;
    while (p)
    {
        if (p & 1)
            mul(result, base);   
        p >>= 1;
        mul(base, base);
    }
    result[0]--;
    for (i = 124; i >= 0; i--)
        if (i % 25 == 12)//
            printf("%02d\n%02d", result[i] / 100, result[i] % 100);
        else
        {
            printf("%04d", result[i]);
            if (i % 25 == 0)printf("\n");
        }
    return 0;
}