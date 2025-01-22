#ifndef AZZR_BITSET
#define AZZR_BITSET
#include "extra_type_trait.cpp"
#include "proxy.cpp"
template<int _Size>
class bitset{
    public:
    #define size (_Size/8+(int)((bool)(_Size%8)))
    unsigned char data[size];
    proxy<for_bitset_proxy> operator[](size_t pos){
        return proxy<for_bitset_proxy>(data[pos/8],pos%8);
    }
    void set0(int begin = 0,int end = size){
        for(int i = begin;i <= end; i++){
            data[0]=0;
        }
    }
    unsigned char* end() const {
        return data + size;
    }
    unsigned char* begin() const {
        return data;
    }
    void operator=(unsigned long long x){
        int cur = 0;
        while(x){
            data[cur++]=(x&0xff);
            x>>=8;
        }
        set0(cur);
    }
    void operator=(const bitset<_Size>& O){
        copy(O.begin(),O.end(),begin());
    }
    #undef size
};
#endif