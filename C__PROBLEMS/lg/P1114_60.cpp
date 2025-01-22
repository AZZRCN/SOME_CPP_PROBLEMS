#include <bits/stdc++.h>
using namespace std;
vector<bool> v;
int n;
int check(int pos){
    int lb=0,lg=0;
    int tb=0,tg=0;
    for(int i = pos; i <= n; i++){
        ((v[i])?(tb++):(tg++));
        if(tb == tg){
            lb = tb;
            lg = tg;
        }
    }
    return lb+lg;
}
int main(){
    bool t;
    cin>>n;
    v.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin>>t;
        v[i]=t;
    }
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        maxn = max(maxn,check(i));
    }
    cout << maxn;
    return 0;
}