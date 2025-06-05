#include <bits/stdc++.h>
using namespace std;
int v[1000][1000];
int n, m;
queue<pair<int,int>> t;
static void process(const pair<int,int>& p) {
    t.push(p);
    v[p.first][p.second]-=2;
    if (p.first+1<n&&v[p.first+1][p.second]>=-2&&v[p.first+1][p.second]<=-1 && v[p.first][p.second]+2 == v[p.first+1][p.second]) process({p.first+1,p.second});
    if (p.first>0&&v[p.first-1][p.second]>=-2&&v[p.first-1][p.second]<=-1 && v[p.first][p.second]+2 == v[p.first-1][p.second]) process({p.first-1,p.second});
    if (p.second+1<n&&v[p.first][p.second+1]>=-2&&v[p.first][p.second+1]<=-1 && v[p.first][p.second]+2 == v[p.first][p.second+1]) process({p.first,p.second+1});
    if (p.second>0&&v[p.first][p.second-1]>=-2&&v[p.first][p.second-1]<=-1 && v[p.first][p.second]+2 == v[p.first][p.second-1]) process({p.first,p.second-1});
}
int main() {
    scanf("%d %d", &n, &m);
    int c;
    int i,j;
    for (i = 0; i < n; i++) {
        c=getchar();
        for (j = 0; j < n; j++) {
            while(c!='0'&&c!='1')(c=getchar());
            v[i][ j] = -((c - '0') ^ ((i + j) & 1))-1;
            c=getchar();
        }
    }

    size_t cnt;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (v[i][ j]>0) continue;
            process({i, j});
            cnt = t.size();
            while(!t.empty()) {
                v[t.front().first][t.front().second] = cnt;
                t.pop();
            }
        }
    }

    int x,y;
    for (i = 0; i < m; i++) {
        scanf("%d %d", &y, &x);
        printf("%d\n", v[y-1][x-1]);
    }

    return 0;
}