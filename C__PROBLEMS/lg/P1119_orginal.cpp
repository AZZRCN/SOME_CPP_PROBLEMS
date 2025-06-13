#include <bits/stdc++.h>
using namespace std;
template<typename...T>class F{tuple<T...>d;public:F(T...v):d(v...){};template<auto I>
auto g(){return get<I>(d);}};template<typename...T>auto mf(T...v){return F<T...>(v...);}
using vvi = vector<vector<int>>; using vvb = vector<vector<bool>>;using vi = vector<int>;
class F5 { int n, I = INT_MAX/2; vvi d;
public:
    void build(vvi &g) { n = g.size(); d.assign(n,vvi::value_type(n,I));
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            d[i][j]=i==j?0:g[i][j]==-1?I:g[i][j];
        for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j)
            if(d[i][k]<I&&d[k][j]<I)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    int dis(int a,int b){return d[a][b]==I?-1:d[a][b];}
};
vector<F<int,int,int,int>> v;
unordered_map<int,int> bt;
int main(){
    int N,M,Q;
    cin >> N >> M;
    int a,b,w;
    for(int i = 0; i < N; i++){
        cin >> a;
        bt.insert(make_pair(i,a));
    }
    for(int i = 1; i <= M ; i++){
        cin >> a >> b >> w;
        v.push_back(mf(max(bt[a],bt[b]),a,b,w));
    }
    sort(v.begin(),v.end(),[](F<int,int,int,int>& a,F<int,int,int,int>& b){
        return a.g<0>()<b.g<0>();
    });
    F5 f;
    vvi m(N,vi(N,-1));
    cin >> Q;
    int current_time = 0,current_pos = 0;
    for(; current_pos<M&&v[current_pos].g<0>()<=0; current_pos++){
        m[v[current_pos].g<1>()][v[current_pos].g<2>()]=v[current_pos].g<3>();
        m[v[current_pos].g<2>()][v[current_pos].g<1>()]=v[current_pos].g<3>();
    }
    current_time = 0;
    f.build(m);
    for(int i = 1; i <= Q; i++){
        cin >> a >> b >> w;
        if(current_time < w){
            for(; current_pos<M&&v[current_pos].g<0>()<=w; current_pos++){
                m[v[current_pos].g<1>()][v[current_pos].g<2>()]=v[current_pos].g<3>();
                m[v[current_pos].g<2>()][v[current_pos].g<1>()]=v[current_pos].g<3>();
            }
            current_time = w;
            f.build(m);
        }
        cout << f.dis(a,b) << endl;
    }
}