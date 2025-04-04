//fail
//发烧,新冠所做抽象代码
#include <bits/stdc++.h>
int main() {
    char K[100], c; int L = 0, C = 0;
    while ((c = getchar_unlocked()) != '\n') K[L++] = c;
    while ((unsigned)((c = getchar_unlocked()) & 0xDF) - 0x41 < 26)
        putchar_unlocked(((26 + (c & 0xDF) - (K[C++] & 0xDF) % 26 + ('A' | (c & 0x20))), C = C == L ? 0 : C));
}