#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bitset<1000000> s;
int read(){
    int x = 0;
    unsigned char c = getchar();
    while((c^'0')>9){
        c = getchar();
    }
    while((c^'0')<10){
        x = (((x<<2)+x)<<1) + (c ^ '0');
        c = getchar();
    }
    return x;
}
int main(){
    int n;
    n = read();
    int x;
    v.resize(n+1);
    for(int i = 1;i<=n;i++){
        v[i]=read();
        for(int j = i-1;j>=1;j--){
            s.set(abs(v[i]-v[j]));
        }
    }
    for(int i = n;i<1000000;i++){
        for(int j = i;j<1000000;j+=i){
            if(s[j]){goto fail;}
        }
        printf("%d\n",i);
        return 0;
        fail:
        ;
    }
}