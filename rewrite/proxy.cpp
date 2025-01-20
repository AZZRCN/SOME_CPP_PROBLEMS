#ifndef AZZR_PROXY
#include "empty_signs.cpp"
#include "io.cpp"
#include "type_trait.cpp"
template<typename _Ty>
class proxy {
public:
    proxy(_Ty& value) : ref_(value) {}

    proxy& operator=(_Ty value) {
        ref_ = value;
        return *this;
    }

    operator _Ty&() const {
        return ref_;
    }

private:
    _Ty& ref_;
};
template<>
class proxy<for_bitset_proxy> {
public:
    proxy(unsigned char& value,unsigned long long _off) : ref_(value),off(_off) {}

    proxy<for_bitset_proxy> operator=(bool value) {
        if(value == true){
            ref_ = (ref_|1<<off);
        }
        else{
            ref_ = (ref_|(0xff^(1<<off)));
        }
        return *this;
    }

    operator bool() const {
        return ((ref_>>off)&1);
    }

private:
    unsigned char& ref_;
    unsigned long long off;
};
template<typename t>
void out::operator()(proxy<t> p){
    // operator()((t)p);
    operator()(static_cast<t>(p.operator t()));
}
template<>
void out::operator()(proxy<for_bitset_proxy> p){
    operator()((bool)p);
}
#define AZZR_PROXY
#endif
int main(){
    int n = 10;
    proxy<int> p(n);
    out o;
    o(p);
}