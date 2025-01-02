#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int> c;
unordered_set<int> s;
signed main(){
    int N,C;
    cin >> N >> C;
    int t;
    unordered_map<int,int>::iterator cit;
    for(int i = 0; i < N; i++){
        cin >> t;
        c[t]++;
        s.insert(t);
    }
    long long ans = 0;
    for(int i:s){
        if(s.find(i-C)!=s.end()){
            ans+=c[i-C]*c[i];
        }
    }
    cout << ans;
}