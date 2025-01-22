//#define repeat(times,i) \
//for(int i = 0; i < times; i++)
//#define Rrepeat(times,i) \
//for(int i = times-1; i>=0; i--)
//#define _repeat(times,i) \
//for(int i = 1; i <= times; i++)
//#define _Rrepeat(times,i) \
//for(int i = times; i>=1; i--)

#define repa(times,i) \
for(int i = 1,end = times; i <= end; i++)
#define repb(times,i,_) \
for(int i = times; i; i--)
#define M3(a, b, c,d) d
#define do(...) M3(__VA_ARGS__, repa,repb)(__VA_ARGS__)