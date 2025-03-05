#include <bits/stdc++.h>
using namespace std;



inline constexpr bool is_digit(const char&c){return ((c>='0')&&(c<='9'));}


//输出
void o(const int*p,int length){
    for(--length; length >= 0; length--){putchar('0'+p[length]);}
}
void o_fixz(const int*p,int length){
    for(--length; length >= 0&&!p[length]; length--);
    for(; length >= 0; length--){putchar('0'+p[length]);}
}

//交换
template<int len>void sw_uncheck_use_extra(int* a,int* b){
    int*p=(int*)malloc(len<<2);
    memcpy(p,a,len<<2);
    memcpy(a,b,len<<2);
    memcpy(b,p,len<<2);
    free(p);p=nullptr;
}
void sw_uncheck(int* a,int* b,int len){while(--len>=0){a[len]^=b[len];b[len]^=a[len];a[len]^=b[len];}}




//交换
void sw(int* a,const int& a_len,int* b,const int& b_len){
    int r = ((a_len<b_len)?a_len:b_len);
    while(--r>=0){a[r]^=b[r];b[r]^=a[r];a[r]^=b[r];}
    if(a_len>b_len){z(a+b_len,a_len-b_len);}
    if(b_len>a_len){z(b+a_len,b_len-a_len);}
}




//置0
void z(int*v,const int&n){memset(v,0,n<<2);}
template<int n>void z(int*v){memset(v,0,n<<2);}



//获取副本
int* get(int*v,int n){
    int*p=(int*)malloc(n<<2);
    // if(p==NULL)return NULL;//内存分配失败检查
    // cp_unckeck(v,p,n);
    memcpy(p, v, n << 2);
    return p;
}
template<int n>int*get(int*v){int*p=(int*)malloc(n<<2);memcpy(p,v,n<<2);return p;}
int*get(int*v,int n){int*p=(int*)malloc(n<<2);memcpy(p,v,n<<2);return p;}


//分配内存
int* mal(const int&n){
    return (int*)malloc(n<<2);
}



//复制
// void cp(int *a, int as, int *b, int bs){
//     int min_len = (as < bs) ? as : bs;
//     // 拷贝共同长度部分
//     memcpy(b, a, min_len * sizeof(int));
//     // 如果b更长，补0
//     if(bs > as) {
//         memset(b + as, 0, (bs - as) * sizeof(int));
//     }
// }
// void cp(int *a, int as, int *b, int bs) {
//     (as < bs) ? (memcpy(b, a, as * sizeof(int)), memset(b + as, 0, (bs - as) * sizeof(int))) : memcpy(b, a, bs * sizeof(int));
// }
// void cp_unckeck(const int* from, int* to, const int& size) {
//     memcpy(to, from, size << 2);
// }

//+1
// void add1(int*v,const int&n){
//     for(int i=0;i<n;i++){
//         if(v[i]!=9){
//             v[i]++;
//             break;
//         }
//         v[i]=0;
//     }
// }
// void add1(int*v,const int&n){
//     int i = 0;
//     a_s:
//     if(i<n){
//         if(v[i]^9){
//             v[i]++;
//             return;
//         }
//         else{v[i]=0;}
//         goto a_s;
//     }
// }
void add1(int*v,const int&n){int i = 0;a_s:if(i<n){if(v[i]^9){v[i]++;return;}else{v[i]=0;}goto a_s;}}




//保存加法结果到新数组
void add2new(
    const int*p,
    const int m,
    const int*q,
    const int n,
          int*r,
    const int k){
    memset(r,0,k<<2);
    const int L = ((((m>n)?m:n)<k)?((m>n)?m:n):k);
    int carry = 0;
    for(int i = 0; i < L; i++){
        if(i<m){carry+=p[i];}
        if(i<n){carry+=q[i];}
        r[i]=carry%10;
        carry/=10;
    }
}







//乘法
// void g(const int*p,int m,const int*q,int n,int*r,int k){if(!p||!q||!r||m<1||n<1||k<1)return;int L=m+n>k?k:m+n;memset(r,0,L*4);for(int i=0;i<m;i++){if(!p[i])continue;for(int j=0;j<n&&i+j<k;j++)r[i+j]+=!q[j]?0:p[i]*q[j];}int c=0,t;for(int i=0;i<L;i++){t=r[i]+c;c=t/10;r[i]=t%10;}}
// void g(const int*p,int m,const int*q,int n,int*r,int k){
//     if(!p||!q||!r||m<1||n<1||k<1)return;
//     int L=k<m+n?k:m+n;
//     memset(r,0,L*4);
//     for(int i=0,j;i<m;i++)if(p[i])
//         for(j=0;j<n&&i+j<k;j++)if(q[j])
//             r[i+j]+=p[i]*q[j];
//     for(int i=0,c=0,t;i<L;r[i++]=t%10)
//         t=r[i]+c,c=t/10;
// }
// void g(const int*p,int m,const int*q,int n,int*r,int k){
//     if(!p||!q||!r||m<1||n<1||k<1)return;
//     int L=(k<m+n?k:m+n);
//     memset(r,0,L<<2);
//     for(int i=0,j,t;i<m;i++)
//         if(p[i])for(j=0;j<n&&i+j<k;j++)
//             r[i+j]+=q[j]?p[i]*q[j]:0;
//     for(int i=0,c=0;i<L;i++)
//         r[i]=(c=(r[i]+c))%10,c/=10;
// }
// void g(const int*p,const int m,const int*q,const int n,int*r,const int k){
//     const int L=(k<m+n?k:m+n);memset(r,0,L<<2);
//     for(int i=0,j,t;i<m;i++)if(p[i])for(j=0;j<n&&i+j<k;j++){r[i+j]+=q[j]?p[i]*q[j]:0;}
//     for(int i=0,c=0;i<L;i++)r[i]=(c=(r[i]+c))%10,c/=10;
// }
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
void g_z(
    const int*p,
    const int m,
    const int*q,
    const int n,
          int*r,
    const int k){
    const int L=(k<m+n?k:m+n);memset(r,0,k<<2);
    for(int i=0,j,t;i<m;i++)if(p[i])for(j=0;j<n&&i+j<k;j++){r[i+j]+=q[j]?p[i]*q[j]:0;}
    for(int i=0,c=0;i<L;i++)r[i]=(c=(r[i]+c))%10,c/=10;
}
template<int m,int n,int k>static void g_z(const int*p,const int*q,int*r){
    constexpr int L=(k<m+n?k:m+n);memset(r,0,k<<2);
    for(int i=0,j,t;i<m;i++)if(p[i])for(j=0;j<n&&i+j<k;j++){r[i+j]+=q[j]?p[i]*q[j]:0;}
    for(int i=0,c=0;i<L;i++)r[i]=(c=(r[i]+c))%10,c/=10;
}
//update
void g4(const int*p,const int&m,const int*q,const int&n,int*r,const int&k){
    const int L=(k<m+n?k:m+n);memset(r,0,L<<2);int carry=0,i=m,j;
    while(i-->=0){if(p[i]){const int p_i=p[i];j=(((n)<(L-i))?(n):(L-i));while(j-->=0){if(q[j]){r[i+j]+=p_i*q[j];}}}}
    for(int i=0;i<L;++i){carry+=r[i];r[i]=carry%10;carry/=10;}
}
void g4_fixz(const int*p,int _m,const int*q,int _n,int*r,const int&k){
    while(_m&&!p[--_m]);while(_n&&!q[--_n]);const int m = _m+1,n=_n+1;
    const int L=(k<m+n?k:m+n);memset(r,0,L/*prefers k,original L*/<<2);int carry=0,i=m,j;
    while(--i>=0){if(p[i]){const int p_i=p[i];j=(((n)<(L-i))?(n):(L-i));while(--j>=0){if(q[j]){r[i+j]+=p_i*q[j];}}}}
    for(int i=0;i<L;++i){carry+=r[i];r[i]=carry%10;carry/=10;}
}


//qpow快速幂
// void qpow(int* __base,const int& base_len,int exp,int* out,const int&out_len){
//     int* base = get(__base,base_len);
//     int* o_temp = (int*)malloc(out_len<<2);
//     int* b_temp = (int*)malloc(base_len<<2);
//     f_unfix(1,out,out_len);
//     while(exp){
//         z(o_temp,out_len);
//         z(b_temp,base_len);
//         if(exp&1){
//             g(base,base_len,out,out_len,o_temp,out_len);
//             sw_uncheck(o_temp,out,out_len);
//         }
//         g(base,base_len,base,base_len,b_temp,base_len);
//         sw_uncheck(b_temp,base,base_len);
//         exp>>=1;
//     }
// }
template<int base_len,int out_len>
void qpow(int* __base,int exp,int* out){
    int* base = get<base_len>(__base);
    int* o_temp = (int*)malloc(out_len<<2);
    int* b_temp = (int*)malloc(base_len<<2);
    f_unfix<out_len>(1,out);
    while(exp){
        z<out_len>(o_temp);
        z<base_len>(b_temp);
        if(exp&1){
            g_z<base_len,out_len,out_len>(base,out,o_temp);
            sw_uncheck_use_extra<out_len>(o_temp,out);
        }
        g_z<base_len,base_len,base_len>(base,base,b_temp);
        sw_uncheck_use_extra<base_len>(b_temp,base);
        exp>>=1;
    }
}


//手动设置一个int n到一个高精度数组
// void f(unsigned x,int*v,const int&n){if(n<1)return;memset(v,0,n*4);int i=0;do{v[i++]=x%10;x/=10;}while(i<n&&x);}
// void f(unsigned x,int*v,const int&n){
//     if(n<1)return;
//     memset(v,0,n*4);
//     for(int i=0;x&&i<n;v[i++]=x%10,x/=10);
// }
// void f(unsigned x,int*v,const int&n){
//     if(n<1)return;
//     memset(v,0,n<<2);
//     for(int i=0;x&&i<n;v[i++]=x%10,x/=10);
// }
void f(unsigned x,int*v,const int&n){memset(v,0,n<<2);for(int i=0;x&&i<n;v[i++]=x%10,x/=10);}
// void f_unfix(unsigned x,int*v,const int&n){for(int i=0;x&&i<n;v[i++]=x%10,x/=10);}
void f_unfix(unsigned x,int*v,const int&const_step){for(int i=0;i<const_step;v[i++]=x%10,x/=10);}
template<int const_step>void f_unfix(unsigned x,int*v){for(int i=0;i<const_step;v[i++]=x%10,x/=10);}


//读取
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
inline constexpr bool is_digit(const char&c){return ((c>='0')&&(c<='9'));}
void __r(int*a,int& p,const int& max_dep){
if(p==max_dep){char t;while(is_digit(t=getchar()));p=0;return;}
char c = getchar();if(is_digit(c)){++p;__r(a,p,max_dep);a[p++]=c-'0';}else{p=0;}}
void r(int*a,const int&a_size){
int p = 0;char c = getchar();while(!is_digit(c)){c=getchar();}
p++;__r(a,p,a_size);a[p++]=c-'0';}




//比较大小
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



// template<typename _Tp,typename Func>
// void count_if(_Tp* arr,ull length,Func _Cond,ull&count){
//     count = 0;
//     while(--length>=0){
//         if(_Cond(arr[length])){
//             count++;
//         }
//     }
// }
template<typename _Tp,typename Func,typename After_Func>
int count_if(_Tp* arr,int length,After_Func After,Func _Cond){
    ull count = 0;
    while(--length>=0&&After(arr[length]));
    while(length>=0){
        if(_Cond(arr[length--])){
            count++;
        }
    }
    return count;
}
// template<typename _Tp,typename Each_Func,typename Cond_Func,typename End_Func>
// void do_while(_Tp val,Each_Func each_to_do,Cond_Func Cond,End_Func End,ull&count){
//     count = 0;
//     while(!End(val)){
//         if(Cond(val)){
//             count++;
//         }
//         val = each_to_do(val);
//     }
// }
// template<typename Cond_Func,typename Act_Func,typename End_Func>
// void do_while(Cond_Func Cond,Act_Func Act,End_Func End){
//     while(!End()){
//         if(Cond()){
//             Act();
//         }
//     }
// }
// template<typename _Tp,typename Each_Func,typename Cond_Func,typename End_Func>
// long long do_while_count(_Tp val,Each_Func each_to_do,Cond_Func Cond,End_Func End){
//     long long count = 0;
//     while(!End(val)){
//         if(Cond(val)){
//             count++;
//         }
//         val = each_to_do(val);
//     }
//     return count;
// }












int main() {
    int a[100],b[100],ret[100];
    memset(a,0,sizeof(a));
    f_unfix(123456788,a,10);
    add(a,100);
    f(987654320,b,100);
    add(b,100);
    g(a,100,b,100,ret,100);
    o(ret,100);
    return 0;
}