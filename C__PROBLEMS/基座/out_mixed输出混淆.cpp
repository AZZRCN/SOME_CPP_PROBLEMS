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