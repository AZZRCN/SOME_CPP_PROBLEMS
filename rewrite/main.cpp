#include <stdlib.h>
#include "io.cpp"
#include "dbg.cpp"
// #include "Book.cpp"
#include "saver.cpp"
#include "reader.cpp"
#include "bitset.cpp"
// #include "io.h" // 引入改进后的 out 类定义
out o;
saver s;
reader r;
#define err(cond) if(cond){throw str_err("Hit An Err Because condition " #cond);}
size_t rcount0(size_t l,size_t r){
    size_t ans = 0;
    l|=r;
    if(!(l&0xffffffff)){ans+=32;l>>=32;}
    if(!(l&0xffff)){ans+=16;l>>=16;}
    if(!(l&0xff)){ans+=8;l>>=8;}
    if(!(l&0xf)){ans+=4;l>>=4;}
    if(!(l&0x3)){ans+=2;l>>=2;}
    if(!(l&0x1)){ans+=1;l>>=1;}
    return ans;
}
bitset<100> bs;
int main() {
    bs[1]=1;
    o(bs[1]);
    return 0;
}