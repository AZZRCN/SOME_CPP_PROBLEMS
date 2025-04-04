#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int,vector<int>,greater_equal<int>> q;
unordered_set<int> m;
vector<int> ans;
void calc(){
    m.insert(1);
    q.push(1);
    ans.push_back(0);
    int f;
    while(ans.size()<=10002){
        f = q.top();
        q.pop();
        ans.push_back(f);
        #define c(x) int t##x = f*x;\
        if(m.find(t##x)==m.end()){\
            m.insert(t##x);\
            q.push(t##x);\
        }
        // ans.push_back(t##x);
        c(2);
        c(3);
        c(5);
        c(7);
    }
}
signed main(){
    calc();
    freopen("P1748.txt","w+",stdout);
    // int n;
    // cin >> n;
    // cout << ans[n];
    for(int i = 1; i <= 10001; i++){
        printf("%lld,",ans[i]);
        if(i%100==0){printf("\n");}
    }
}