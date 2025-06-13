#include <cstring>
#include <type_traits>
#include <stdio.h>
struct Out{
    enum{B=1<<20};char b[B];size_t p=0;
    __forceinline void f(){if(p)fwrite(b,1,p,stdout),p=0;}
    __forceinline void w(char c){p==B?f():void();b[p++]=c;}
    template<class T> __forceinline void u(T n){
        char t[32];int i=0;do t[i++]='0'+n%10;while(n/=10);
        while(i--)w(t[i]);}
public:
    template<class T> __forceinline void W(T v){
        if constexpr(std::is_same_v<T,const char*>){
            size_t l=strlen(v),r=B-p;
            l<=r?memcpy(b+p,v,l),p+=l:(memcpy(b+p,v,r),p+=r,f(),memcpy(b,v+r,l-r),p+=l-r);}
        else if constexpr(std::is_integral_v<T>){
            if constexpr(std::is_signed_v<T>){if(v<0)w('-'),v=-v;}
            !v?w('0'):u(std::make_unsigned_t<T>(v));}}
    template<class T> Out& operator<<(T x){W(x);return*this;}
    ~Out(){f();}};

// 使用示例
Out out;
int main()
{
    out
        << 123
        << " test "
        << -456
        << " "
        << 0;
}

template<typename T>void __out(T x){if(x)__out(x/10),putchar(x%10+'0');}
template<typename T>void out(T x){x?__out(x),0:putchar('0');}

#include <bits/stdc++.h>
using namespace std;
#define Z (1<<(5<<2))
class O{char m[Z];size_t p=0;
__forceinline void*f(){p?fwrite(m,1,p,stdout),p=0:0;return nullptr;}
__forceinline void q(char c){(p==Z)?f():0;m[p++]=c;}
template<class T>void wu(T n){char t[(((sizeof(T)<<2)|11))];int i=0;
do t[i++]=(n%10)|48;while(n/=10);while(i--)q(t[i]);}
public:template<class T>O&operator<<(T v){if constexpr(is_same
<T,char*>::value||is_same<T,const char*>::value){size_t l=0;while(
v[l])l++;size_t r=Z-p;(l<=r?memcpy(m+p,v,l),p+=l:(memcpy(m+p,v,r),
p+=r,f(),memcpy(m,v+r,l-r),p+=l-r)),0;}else if constexpr(is_integral
<T>::value){if constexpr(is_signed<T>::value)v<0?q(45),v=-v,0:0;!v?q
(48):wu((typename make_unsigned<T>::type)v);}return*this;}O&operator\
<<(char c){q(c);return*this;}~O(){f();}};




























////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//原始oi部分

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    const size_t en = vec.size();
    for(int i = 0; i < en; i++){
        cout << vec[i];
        if(i+1<en){
            cout << ',';
        }
    }
    os << "}";
    return os;
}

template <typename t1, typename t2>
std::ostream& operator<<(std::ostream& os, const std::pair<t1,t2>& p) {
    os << "{" << p.first << "," << p.second << "}";
    return os;
}

template <typename t1, typename t2>
std::ostream& operator<<(std::ostream& os, const std::map<t1,t2>& mp) {
    os << "{";
    int pos = 0;
    const int en = mp.size();
    for(pair<t1,t2> i:mp){
        cout << "{" << i.first << "," << i.second << "}";
        if(pos + 1 < en){
            pos++;
            cout << ",\n";
        }
    }
    os << "}";
    return os;
}

auto in = [&](int& x)->void{
    x = 0;
    bool zf = true;
    char c=getchar();
    if(c == '+' || c == '-'){
        zf=(c=='-');
        c=getchar();
    }
    while(digit(c)){
        x = x * 10 + (c-'0');
        c=getchar();
    }
    if(!zf)x=-x;
};

static void out(int x,const int& begin = 30,const char& end = ' ')
{
    char* p = sta + begin;
    if(end != '\0'){
        *(p--) = end;
    }
    do{
        *(p--) = ((x%10)|0x30);
        x/=10;
    } while (x);
    fwrite(p+1,sizeof(char),sta+30-p,stdout);
}

inline void out_pro(int x,int length,char fill_char = ' ',char end_char = '\0'){
    int i = length - oi::dec_len(x);
    printf("%d",x);while(i--){putchar(fill_char);}putchar(end_char);
}

void out(data_struct::heap::heap_arr_greater o,const char end = '\n'){
    for(int i = 1; i <= o.length; i++){
        printf("%d ",o.data[i]);
    }
    putchar(end);
}