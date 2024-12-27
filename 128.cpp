#include <iostream>
#include <cinttypes>
#include <cstring>
using namespace std;
#define a32 0xFFFFFFFF
#define p32 >>=32
#define a16 0xFFFF
#define l(x) (x&a16)
#define h(x) ((x>>16)&a16)
class uint64{
    public:
    uint32_t data[2];
    uint32_t temp[4];
    // void operator=(uint32_t x){
    //     data[0] = x&a32;

    //     data[1] = 0;
    // }
    void operator=(uint64_t x){
        data[0] = x&a32;
        x p32;
        data[1] = x&a32;
    }
    __forceinline void ctemp(){
        memset(temp,0,sizeof(temp));
    }
    __forceinline void ftemp(){
        temp[0] &= a16;
        temp[1] &= a16;
        temp[2] &= a16;
        temp[3] &= a16;
    }
    void fix(){
        temp[3] += ((temp[2]>>16)&a16);
        temp[2] += ((temp[1]>>16)&a16);
        temp[1] += ((temp[0]>>16)&a16);
        temp[0] &= a16;
        temp[1] &= a16;
        temp[2] &= a16;
        temp[3] &= a16;
    }
    // void operator*(uint64 x) {
    //     ctemp();
    //     uint32_t low_low = (data[0] & a16) * (x[0] & a16);
    //     uint32_t low_high = (data[0] & a16) * ((x[0] >> 16) & a16);
    //     uint32_t high_low = ((data[0] >> 16) & a16) * (x[0] & a16);
    //     uint32_t high_high = ((data[0] >> 16) & a16) * ((x[0] >> 16) & a16);
    //     temp[0] = low_low & a16;
    //     temp[1] = (low_low >> 16) + (low_high & a16) + (high_low & a16);
    //     temp[2] = (low_high >> 16) + (high_low >> 16) + high_high;
    //     fix();
    //     low_low = (data[1] & a16) * (x[1] & a16);
    //     low_high = (data[1] & a16) * ((x[1] >> 16) & a16);
    //     high_low = ((data[1] >> 16) & a16) * (x[1] & a16);
    //     high_high = ((data[1] >> 16) & a16) * ((x[1] >> 16) & a16);
    //     temp[2] += low_low & a16;
    //     temp[3] = (low_low >> 16) + (low_high & a16) + (high_low & a16);
    //     temp[3] += (low_high >> 16) + (high_low >> 16) + high_high;
    //     fix();
    //     low_low = (data[0] & a16) * (x[1] & a16);
    //     low_high = (data[0] & a16) * ((x[1] >> 16) & a16);
    //     high_low = ((data[0] >> 16) & a16) * (x[1] & a16);
    //     high_high = ((data[0] >> 16) & a16) * ((x[1] >> 16) & a16);
    //     temp[1] += low_low & a16;
    //     temp[2] += (low_low >> 16) + (low_high & a16) + (high_low & a16);
    //     temp[3] += (low_high >> 16) + (high_low >> 16) + high_high;
    //     fix();
    //     data[0] = (temp[0] | (temp[1] << 16));
    //     data[1] = (temp[2] | (temp[3] << 16));
    // }
    void apply(){
        data[0] = ((temp[0])|(temp[1]<<16));
        data[1] = ((temp[2])|(temp[3]<<16));
    }
    void operator*(uint64 x){
        ctemp();
        temp[0] += l(x[0])*l(data[0]);
        fix();
        temp[1] += h(x[0])*l(data[0]);
        temp[1] += l(x[0])*h(data[0]);
        fix();
        temp[2] += l(x[1])*l(data[0]);
        temp[2] += h(x[0])*h(data[0]);
        temp[2] += l(x[0])*l(data[1]);
        fix();
        temp[3] += h(x[1])*l(data[0]);
        temp[3] += l(x[1])*h(data[0]);
        temp[3] += h(x[0])*l(data[1]);
        temp[3] += l(x[0])*h(data[1]);
        fix();
        apply();
    }
    uint32_t operator[](uint32_t x){
        return data[x];
    }
    uint64(uint32_t x){
        data[0] = x;
        data[1] = 0;
    }
    uint64(void){
        data[0] = data[1] = 0;
    }
    void operator&=(uint64 x){
        data[0] &= x[0];
        data[1] &= x[1];
    }
    void operator>>=(uint32_t x){
        data[0]=((data[0]>>x)|(data[1]<<(32-x)));
        data[1]=(data[1]>>x);
    }
};
#undef l
#undef h
#define h(x) ((x>>32)&a32)
#define l(x) (x&a32)
#define a a32
class uint128{
    public:
    uint64_t data[2];
    uint64_t temp[4];
    void operator=(uint64_t x){
        data[0] = x;
        data[1] = 0;
    }
    __forceinline void ctemp(){
        memset(temp,0,sizeof(temp));
    }
    __forceinline void ftemp(){
        temp[0] &= a32;
        temp[1] &= a32;
        temp[2] &= a32;
        temp[3] &= a32;
    }
    void fix(){
        temp[3] += ((temp[2]>>32)&a32);
        temp[2] += ((temp[1]>>32)&a32);
        temp[1] += ((temp[0]>>32)&a32);
        temp[0] &= a32;
        temp[1] &= a32;
        temp[2] &= a32;
        temp[3] &= a32;
    }
    void apply(){
        data[0] = ((temp[0])|(temp[1]<<32));
        data[1] = ((temp[2])|(temp[3]<<32));
    }
    void operator*(uint128 x){
        ctemp();
        temp[0] += l(x[0])*l(data[0]);
        fix();
        temp[1] += h(x[0])*l(data[0]);
        temp[1] += l(x[0])*h(data[0]);
        fix();
        temp[2] += l(x[1])*l(data[0]);
        temp[2] += h(x[0])*h(data[0]);
        temp[2] += l(x[0])*l(data[1]);
        fix();
        temp[3] += h(x[1])*l(data[0]);
        temp[3] += l(x[1])*h(data[0]);
        temp[3] += h(x[0])*l(data[1]);
        temp[3] += l(x[0])*h(data[1]);
        fix();
        apply();
    }
    uint64_t operator[](uint32_t x){
        return data[x];
    }
};
#undef l
#undef a
#undef h
void out(uint64 x){
    printf("temp:%10x %10x %10x %10x\ndata:%10x %10x\n",x.temp[3],x.temp[2],x.temp[1],x.temp[0],x.data[1],x.data[0]);
}
void out(uint128 x){
    printf("temp:%10llx %10llx %10llx %10llx\ndata:%10llx %10llx\n",x.temp[3],x.temp[2],x.temp[1],x.temp[0],x.data[1],x.data[0]);
}
int main(){
    uint128 a,b;
    a = 100000000ULL;
    b = 100000000ULL;
    a * b;
    out(a);
    // a>>=4;
    // out(a);
    // 23 86F2 6FC1 0000
}