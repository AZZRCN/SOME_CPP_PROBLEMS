#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000001];
int v[1000001];
int len[1000001];
queue<int>wait;
void update(int k){
    for(int i : adj[k]){
        if(len[i]<len[k]+1){
            continue;
        }
        if(len[i]==len[k]+1){
            v[i]+=v[k];
        }
        if(len[i]>len[k]+1){
            len[i]=len[k]+1;
            v[i]=v[k];
            wait.push(i);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    memset(len,0x3f,sizeof(len));
    memset(v,0,sizeof(v));
    int N,M;
    cin >> N >> M;
    int a,b;
    for(int i = 1; i <= M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v[1]=1;
    wait.push(1);
    len[1] = 0;
    while(!wait.empty()){
        int t = wait.front();
        wait.pop();
        update(t);
    }
    for(int i = 1; i <= N; i++){
        cout << ((len[i]==0x3f3f3f3f)?(0):(v[i]%100003)) << endl;
        // cout << len[i] << endl;
    }
}