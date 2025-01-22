#include <stdlib.h>
#include "io.cpp"
#include "dbg.cpp"
#include "arr.cpp"
#include "pairs.cpp"
#include "defines.cpp"
out o;
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
int main() {
    arr<int,5> v;
    v.set(1);
}