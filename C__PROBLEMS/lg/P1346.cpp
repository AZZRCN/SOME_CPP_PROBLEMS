#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>; using vi = vector<int>;
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
int main(){
    int N,A,B,t,tt;
    cin >> N >> A >> B;
    vvi m;
    m.resize(N,vi(N,-1));
    for(int i = 0; i < N; i++){
        cin >> t;
        for(int j = 0; j < t; j++){
            cin >> tt;
            if(j==0){
                m[i][tt-1]=0;
            }
            else{
                m[i][tt-1]=1;
            }
        }
    }
    F5 f(m);
    cout << f.dis(A-1,B-1);
}