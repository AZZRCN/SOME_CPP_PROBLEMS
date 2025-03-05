#include <bits/stdc++.h>
using namespace std;
int lcount0u32(uint32_t x){
    int ans = 0;
    if(!(x&0xffff0000))
    {ans+=16;x<<=16;}
    if(!(x&0xff000000))
    {ans+=8;x<<=8;}
    if(!(x&0xf0000000))
    {ans+=4;x<<=4;}
    if(!(x&0xc0000000))
    {ans+=2;x<<=2;}
    if(!(x&0x80000000))
    {ans+=1;x<<=1;}
    if(!(x&0x80000000))
    {ans+=1;x<<=1;}
    return ans;
}
template<typename t>
__forceinline constexpr bool is_neg(const t& val){
    return (val>>(sizeof(t)*8-1));
}
class Solution {
public:
    int divide(int a, int b) {
        if (a == INT32_MIN && b == -1) {
            return INT32_MAX;
        }
        if (a == INT32_MIN && b == 1) {
            return INT32_MIN;
        }
        if (b == INT32_MIN) {
            return (a == INT32_MIN) ? 1 : 0;
        }
        bool flag = ((a < 0) ^ (b < 0));
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        int ans = 0;
        int multi = lcount0u32(b);
        for (int i = multi; i >= 0; i--) {
            if (a >= (b << i)) {
                a -= (b << i);
                ans += (1 << i);
            }
        }
        return flag ? -ans : ans;
    }
};