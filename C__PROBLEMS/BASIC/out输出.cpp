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