#include <bits/stdc++.h>
using namespace std;
#define int long long
int Q;
int l,r;
void invoke(){
    int repeats = (r-l+1)/9;
    l += repeats*9;
    int t = 0;
    for(;l<=r;l++){
        t+=l;
    }
    cout << (t%9) << endl;
}
signed main(){
    cin >> Q;
    while(Q-->0){
        cin>>l>>r;
        invoke();
    }
}