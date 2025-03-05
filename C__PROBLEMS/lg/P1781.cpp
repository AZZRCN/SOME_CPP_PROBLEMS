#include <bits/stdc++.h>
using namespace std;
int ans[100],ansn,temp[100];
inline bool is_digit(const char&c){
    return ((c>='0')&&(c<='9'));
}
void __r(int*a,int& p,const int& max_dep){
    if(p==max_dep){
        char t;
        while(is_digit(t=getchar()));
        p=0;
        return;
    }
    char c = getchar();
    if(is_digit(c)){
        ++p;
        __r(a,p,max_dep);
        a[p++]=c-'0';
    }else{
        p=0;
    }
}
void r(int*a,const int&a_size){
    int p = 0;
    char c = getchar();
    while(!is_digit(c)){
        c=getchar();
    }
    p++;
    __r(a,p,a_size);
    a[p++]=c-'0';
}
bool big(const int*a,const int&a_size,const int*b,const int&b_size){
    if(a_size>b_size){
        for(int i = a_size-1;i>=b_size;i--){
            if(a[i])return true;
        }
    }
    if(a_size<b_size){
        for(int i = b_size-1;i>=a_size;i--){
            if(b[i])return false;
        }
    }
    for(int i = min(a_size,b_size)-1;i>=0;i--){
        if(a[i]^b[i]){
            return a[i]>b[i];
        }
    }
    return false;
}
void sw_uncheck(int* a,int* b,int len){while(--len>=0){a[len]^=b[len];b[len]^=a[len];a[len]^=b[len];}}
void o_fixz(const int*p,int length){
    for(--length; length >= 0&&!p[length]; length--);
    for(; length >= 0; length--){putchar('0'+p[length]);}
}
int main(){
    int n,t=0;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        r(temp,100);
        if(big(temp,100,ans,100)){
            sw_uncheck(ans,temp,100);
            ansn=i;
        }
    }
    cout << ansn << endl;
    o_fixz(ans,100);
}