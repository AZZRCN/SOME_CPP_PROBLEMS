#ifndef AZZR_BITSET
#include "type_trait.cpp"
#include "proxy.cpp"
template<int size>
class bitset{
    public:
    unsigned char data[size/8+(int)((bool)(size%8))];
    proxy<for_bitset_proxy> operator[](size_t pos){
        return proxy<for_bitset_proxy>(data[pos/8],pos%8);
    }
};
#define AZZR_BITSET
#endif