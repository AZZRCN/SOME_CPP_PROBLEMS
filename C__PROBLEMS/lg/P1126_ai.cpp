#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0};  // 北 南 东 西
const int dy[] = {0, 0, 1, -1};

int N, M;
int mp[50][50];
int dist[51][51][4];

struct State {
    int x, y, dir;
};

bool valid(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > M) return false;
    for (int dx = 0; dx <= 1; ++dx)
        for (int dy = 0; dy <= 1; ++dy) {
            int nx = x - dx, ny = y - dy;
            if (nx < 1 || ny < 1 || nx > N || ny > M) return false;
            if (mp[nx - 1][ny - 1]) return false;
        }
    return true;
}

queue<State> q;

void bfs(int sx, int sy, int ex, int ey, char sf) {
    memset(dist, 0x3f, sizeof(dist));
    int start_dir;
    switch (sf) {
        case 'N': start_dir = 0; break;
        case 'S': start_dir = 1; break;
        case 'E': start_dir = 2; break;
        case 'W': start_dir = 3; break;
    }

    if (!valid(sx, sy)) return;

    dist[sx][sy][start_dir] = 0;
    q.push({sx, sy, start_dir});

    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();

        // 转向操作
        for (int nd : {(d + 1) % 4, (d + 3) % 4}) {
            if (dist[x][y][nd] > dist[x][y][d] + 1) {
                dist[x][y][nd] = dist[x][y][d] + 1;
                q.push({x, y, nd});
            }
        }

        // 前进操作
        for (int step = 1; step <= 3; ++step) {
            int nx = x + dx[d] * step, ny = y + dy[d] * step;
            if (!valid(nx, ny)) break;
            if (dist[nx][ny][d] > dist[x][y][d] + 1) {
                dist[nx][ny][d] = dist[x][y][d] + 1;
                q.push({nx, ny, d});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> mp[i][j];

    int sx, sy, ex, ey;
    char sf;
    cin >> sx >> sy >> ex >> ey >> sf;

    if (!valid(sx, sy) || !valid(ex, ey)) {
        cout << -1 << endl;
        return 0;
    }

    bfs(sx, sy, ex, ey, sf);

    int res = INF;
    for (int d = 0; d < 4; ++d)
        res = min(res, dist[ex][ey][d]);

    cout << (res == INF ? -1 : res) << endl;
    return 0;
}