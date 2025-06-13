//为什么对啊???????

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001; // 最大顶点数
const int MOD = 100003;   // 模数

vector<int> adj[MAXN];    // 邻接表
int v[MAXN];              // 最短路计数
int len[MAXN];            // 最短距离
queue<int> wait;          // BFS 队列

// 更新函数
void update(int k) {
    for (int i : adj[k]) {
        if (len[i] < len[k] + 1) continue; // 如果已经有更短的路径，跳过
        if (len[i] == len[k] + 1) {       // 如果路径长度相等，累加计数
            v[i] = (v[i] + v[k]) % MOD;
        }
        if (len[i] > len[k] + 1) {        // 如果找到更短的路径，更新计数
            len[i] = len[k] + 1;
            v[i] = v[k];
            wait.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 初始化邻接表
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 初始化距离和计数
    memset(len, 0x3f, sizeof(len)); // 距离初始化为无穷大
    v[1] = 1;                      // 起点到自身的路径计数为 1
    len[1] = 0;                    // 起点到自身的距离为 0
    wait.push(1);                  // 将起点加入队列

    // BFS 遍历
    while (!wait.empty()) {
        int k = wait.front();
        wait.pop();
        update(k);
    }

    // 输出结果
    for (int i = 1; i <= N; i++) {
        cout << (len[i] == 0x3f3f3f3f ? 0 : v[i]) << "\n";
    }

    return 0;
}