#include <vector>
#include <climits>
using namespace std;

// F1: 所有边权为正数 (w > 0), 无辅助矩阵, -1 表示无边
class Floyd_Version1 {
private:
    int n, INF = INT_MAX / 2;
    vector<vector<int>> dist;

    void initialize(const vector<vector<int>>& graph) {
        n = graph.size();
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) dist[i][j] = 0;
                else if (graph[i][j] == -1 || graph[i][j] <= 0)
                    dist[i][j] = INF; // 只允许 w > 0
                else
                    dist[i][j] = graph[i][j];
            }
        }
    }

public:
    Floyd_Version1(const vector<vector<int>>& graph) {
        initialize(graph);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int distance(int from, int to) {
        return dist[from][to] == INF ? -1 : dist[from][to];
    }
};

// F2: 非负权边 (w ≥ 0), 有辅助矩阵, 支持 0 权值
class Floyd_Version2 {
private:
    int n, INF = INT_MAX / 2;
    vector<vector<int>> dist;

    void initialize(const vector<vector<int>>& graph,
                    const vector<vector<bool>>& cango) {
        n = graph.size();
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) dist[i][j] = 0;
                else if (cango[i][j]) dist[i][j] = graph[i][j];
                else dist[i][j] = INF;
    }

public:
    Floyd_Version2(const vector<vector<int>>& graph,
                   const vector<vector<bool>>& cango) {
        initialize(graph, cango);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int distance(int from, int to) {
        return dist[from][to] == INF ? -1 : dist[from][to];
    }
};

// F3: 允许负权边 (w ∈ ℤ), 有辅助矩阵
class Floyd_Version3 {
private:
    int n, INF = INT_MAX / 2;
    vector<vector<int>> dist;

    void initialize(const vector<vector<int>>& graph,
                    const vector<vector<bool>>& cango) {
        n = graph.size();
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) dist[i][j] = 0;
                else if (cango[i][j]) dist[i][j] = graph[i][j];
                else dist[i][j] = INF;
    }

public:
    Floyd_Version3(const vector<vector<int>>& graph,
                   const vector<vector<bool>>& cango) {
        initialize(graph, cango);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int distance(int from, int to) {
        return dist[from][to] == INF ? -1 : dist[from][to];
    }
};

// F4: 无辅助矩阵但支持负权边（用 0 表示无边）
class Floyd_Version4 {
private:
    int n, INF = INT_MAX / 2;
    vector<vector<int>> dist;

    void initialize(const vector<vector<int>>& graph) {
        n = graph.size();
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) dist[i][j] = 0;
                else if (graph[i][j] != 0) dist[i][j] = graph[i][j];
                else dist[i][j] = INF;
    }

public:
    Floyd_Version4(const vector<vector<int>>& graph) {
        initialize(graph);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int distance(int from, int to) {
        return dist[from][to] == INF ? -1 : dist[from][to];
    }
};

// F5: 非负权边, 无辅助矩阵, -1 表示无边
class Floyd_Version5 {
private:
    int n, INF = INT_MAX / 2;
    vector<vector<int>> dist;

    void initialize(const vector<vector<int>>& graph) {
        n = graph.size();
        dist.assign(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) dist[i][j] = 0;
                else if (graph[i][j] == -1) dist[i][j] = INF;
                else dist[i][j] = graph[i][j];
    }

public:
    Floyd_Version5(const vector<vector<int>>& graph) {
        initialize(graph);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int distance(int from, int to) {
        return dist[from][to] == INF ? -1 : dist[from][to];
    }
};






//ultimate





#include <vector>
#include <climits>
using namespace std; using vvi = vector<vector<int>>; using vvb = vector<vector<bool>>;

// F1: w > 0, no helper, -1 means no edge
class F1 { int n, I = INT_MAX/2; vvi d;
public:
    F1(vvi &g) { n = g.size(); d.assign(n, vvi::value_type(n, I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:(g[i][j]==-1||g[i][j]<=0)?I:g[i][j];
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};

// F2: w >= 0, with helper matrix
class F2 { int n, I = INT_MAX/2; vvi d;
public:
    F2(vvi &g, vvb &c) { n = g.size(); d.assign(n,vvi::value_type(n,I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:c[i][j]?g[i][j]:I;
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};

// F3: w ∈ ℤ, with helper matrix
class F3 { int n, I = INT_MAX/2; vvi d;
public:
    F3(vvi &g, vvb &c) { n = g.size(); d.assign(n,vvi::value_type(n,I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:c[i][j]?g[i][j]:I;
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};

// F4: w ∈ ℤ, no helper, 0 means no edge
class F4 { int n, I = INT_MAX/2; vvi d;
public:
    F4(vvi &g) { n = g.size(); d.assign(n,vvi::value_type(n,I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:g[i][j]?g[i][j]:I;
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};

// F5: w >= 0, no helper, -1 means no edge
class F5 { int n, I = INT_MAX/2; vvi d;
public:
    F5(vvi &g) { n = g.size(); d.assign(n,vvi::value_type(n,I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:g[i][j]==-1?I:g[i][j];
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};