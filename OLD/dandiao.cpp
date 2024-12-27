#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <list>
using namespace std;
template <int x>
class dandiao {
public:
    list<int> minn;
    list<int> maxn;
    int n, k;
    int a[x + 1];
    void inline init() {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
    }
    void inline init_args() {//request two between args:n and k
        scanf("%d %d", &n, &k);
    }
    void inline init_to_k() {
        for (int i = 1; i <= k; i++) {
            minn_push(i);
            maxn_push(i);
        }
    }
    void inline minn_push(int pos) {
        if (!minn.empty() && minn.front() == pos - k) {
            minn.pop_front();
        }
        while (!minn.empty() && a[pos] < a[minn.back()]) {
            minn.pop_back();
        }
        minn.push_back(pos);
    }
    void inline maxn_push(int pos) {
        if (!maxn.empty() && maxn.front() == pos - k) {
            maxn.pop_front();
        }
        while (!maxn.empty() && a[pos] > a[maxn.back()]) {
            maxn.pop_back();
        }
        maxn.push_back(pos);
    }
    void builtin() {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
            minn_push(i);
            maxn_push(i);
        }
        for (int i = k + 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
    }
    //格式要求:n k (\n) n*values
    //p格式要求与调用函数参数一致
    void builtin_final(void (*p)()) {//在k+1到n都执行一遍p函数
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
            minn_push(i);
            maxn_push(i);
        }
        p();
        for (int i = k + 1; i <= n; i++) {
            scanf("%d", &a[i]);
            minn_push(i);
            maxn_push(i);
            p();
        }
    }
};
//eg:
/*
(the thing above)
void act() {};
dandiao<2000000> D;
int main() {
    D.builtin_final(act);
    system("pause");
    return 0;
}
*/