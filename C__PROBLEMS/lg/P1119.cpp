#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>; using vvb = vector<vector<bool>>;using vi = vector<int>;
class F5 { int n, I = INT_MAX/2;
public:
    vvi d;
    F5(int __n){n=__n;d = vvi(n,vi(n,I));};
    void build(int k){
        for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    void add(int f,int t,int w){
        if(d[f][t]>w)d[f][t]=w;
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};
unordered_map<int,vi> t2p;
unordered_map<int,int> p2t;
int main(){
    int N,M,Q;
    cin >> N >> M;
    int a,b,w;
    for(int i = 0; i < N; i++){
        cin >> a;
        t2p[a].push_back(i);
        p2t.insert(make_pair(i,a));
    }
    F5 f(N);
    for(int i = 1; i <= M ; i++){
        cin >> a >> b >> w;
        f.add(a,b,w);
        f.add(b,a,w);
    }
    cin >> Q;
    int current_time = 0;
    for(auto k: t2p[0]){
        f.build(k);
    }
    current_time = 0;
    for(int i = 1; i <= Q; i++){
        cin >> a >> b >> w;
        for(; current_time <= w; current_time++){
            for(auto k: t2p[current_time]){
                f.build(k);
            }
        }
        if(p2t[a]>w||p2t[b]>w){
            puts("-1");
            continue;
        }
        cout << f.dis(a,b) << endl;
    }
}