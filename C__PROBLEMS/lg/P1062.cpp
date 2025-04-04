#include <bits/stdc++.h>
using namespace std;
template<typename T>void __out(T x){if(x)__out(x/10),putchar(x%10+'0');}
template<typename T>void out(T x){x?__out(x),0:putchar('0');}
int main(){
    unsigned long long k,n,t;
    cin >> k >> n;
    __uint128_t x = 0;
    t = 1;
    while(n){
        if (n & 1) { 
            x += t;
        }
        t *= k; 
        n >>= 1;    
    }
    out(x);
}