//神秘代码
//神秘代码
//神秘代码
//重要的事情说三遍
#include <cstdio>
#include <cstring>

const int LEN = 500;
int base[LEN] = {2}, res[LEN] = {1}, temp[LEN], t[LEN];

inline void multiply(int* a, int* b, int* out) {
    memset(temp, 0, LEN*4);
    
    // 循环展开4次
    for (int i = 0; i < LEN; ++i) {
        if (!a[i]) continue;
        int *pb = b, *pt = temp + i;
        int cnt = LEN - i;
        for (; cnt >= 4; cnt -= 4) {
            *pt++ += a[i] * *pb++;
            *pt++ += a[i] * *pb++;
            *pt++ += a[i] * *pb++;
            *pt++ += a[i] * *pb++;
        }
        while (cnt--) *pt++ += a[i] * *pb++;
    }

    // 进位处理展开
    for (int i = 0; i < LEN-1; ++i) {
        if (temp[i] >= 10) {
            int carry = temp[i] / 10;
            temp[i+1] += carry;
            temp[i] -= carry * 10;
        }
    }
    temp[LEN-1] %= 10;
    memcpy(out, temp, LEN*4);
}

inline void pow2(int p) {
    while (p) {
        if (p & 1) {
            multiply(res, base, t);
            memcpy(res, t, LEN*4);
        }
        multiply(base, base, t);
        memcpy(base, t, LEN*4);
        p >>= 1;
    }
}

int main() {
    int P;
    scanf("%d", &P);
    
    // 精确计算位数
    printf("%lld\n", (long long)(P * 0.3010299957) + 1);
    
    pow2(P);
    
    // 处理减1
    for (int i = 0; i < LEN; ++i) {
        if (res[i]) { --res[i]; break; }
        res[i] = 9;
    }

    // 预生成输出缓冲区
    char buf[500*2 + 20];
    char* p = buf;
    for (int i = 499, c = 0; i >= 0; --i, ++c) {
        *p++ = res[i] + '0';
        if (c == 49) { *p++ = '\n'; c = -1; }
    }
    *p = 0;
    
    // 块输出
    fwrite(buf, 1, p - buf, stdout);
    return 0;
}