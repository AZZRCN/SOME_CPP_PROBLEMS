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
constexpr char* c =
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "1234567890"
                "!@#$%^&*()-=_=[]{}|:;<>,.?/~`";
constexpr int len = strlen(c);
void out(uint64_t x){
    do{
        putchar(c[x%len]);
        x/=len;
    }while(x);
}
signed main(){
    freopen("P1748_pre_4.cpp","wb+",stdout);
    calc();
    printf(R"(#include <bits/stdc++.h>
using namespace std;
const vector<string> ans = {)");
    for(int i = 0; i <= 10001; i++){
        putchar('\"');
        out(ans[i]);
        putchar('\"');
        putchar(',');
        if(i%100==0){
            putchar('\n');
        }
    }
    printf(R"(};)");
    putchar('\n');
    printf(R"(constexpr map<int,int> unconverter = {)");
    for(int i = 0; i < len; i++){
        if(i!=0)putchar(',');
        printf("{\'%c\',%d}",c[i],i);
    }
    printf(R"(};)");
}