#include <bits/stdc++.h>
using namespace std;
void f_unfix(unsigned x,int*v,const int&const_step){for(int i=0;i<const_step;v[i++]=x%10,x/=10);}
void sw_uncheck(int* a,int* b,int len){while(--len>=0){a[len]^=b[len];b[len]^=a[len];a[len]^=b[len];}}
void g(
    const int*p,
    const int m,
    const int*q,
    const int n,
          int*r,
    const int k){
    const int L=(k<m+n?k:m+n);memset(r,0,L<<2);
    for(int i=0,j,t;i<m;i++)if(p[i])for(j=0;j<n&&i+j<k;j++){r[i+j]+=q[j]?p[i]*q[j]:0;}
    for(int i=0,c=0;i<L;i++)r[i]=(c=(r[i]+c))%10,c/=10;
}
void o_fixz(const int*p,int length){
    for(--length; length >= 0&&!p[length]; length--);
    for(; length >= 0; length--){putchar('0'+p[length]);}
}
void add(
    const int*p,
    const int m,
          int*q,
    const int n){
    int carry = 0;
    for(int i = 0; (i < m||carry)&&i<n; i++){
        if(i<m){carry+=p[i];}
        carry+=q[i];
        q[i]=carry%10;
        carry/=10;
    }
}
constexpr int len = 100;
int a[2],b[len],ret[len],__[len];
int main() {
    int n;
    scanf("%d",&n);
    f_unfix(1,b,1);
    for(int i = 1; i <= n; i++){
        f_unfix(i,a,2);
        g(a,2,b,len,ret,len);
        sw_uncheck(b,ret,len);
        add(b,len,__,len);
    }
    o_fixz(__,len);
    return 0;
}