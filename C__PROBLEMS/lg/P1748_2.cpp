#pragma GCC diagnostic ignored "-Wmultichar"
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
void out(uint64_t x){
    putwchar(x&0xffff);
    putwchar((x>>16)&0xffff);
    putwchar((x>>32)&0xffff);
    putwchar((x>>48)&0xffff);
}
signed main(){
    // calc();
    // _wfreopen(L"P1748_pre_2.cpp",L"wb+",stdout);
    // for(int i = 0; i <= 10001; i++){
    //     // putwchar(L'\"');
    //     // out(ans[i]);
    //     // putwchar(L'\"');
    //     // putwchar(L',');
    //     // if(i%100==0){
    //     //     putwchar(L'\n');
    //     //     '\n';
    //     // }
    //     out(ans[i]);
    // }
    cout << (unsigned int)('ABC');
}