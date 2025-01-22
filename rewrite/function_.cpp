#ifndef AZZR_FUNCTION
#define AZZR_FUNCTION
#include <crtdefs.h>
#include "extra_type_trait.cpp"
constexpr inline
size_t min(const size_t& a,const size_t& b){
    return ((a<b)?(a):(b));
}
template<typename _Tp>
class less{
    constexpr bool operator()(const _Tp& x,const _Tp& y){
        return x < y;
    }
};
template<typename _Tp>
inline void swap(_Tp&x, _Tp&y) noexcept{_Tp t = x;x = y;y = t;}
// template<typename _Tp>
// constexpr typename remove_reference<_Tp>::type&&
// move(_Tp&& __t) noexcept
// { return static_cast<typename remove_reference<_Tp>::type&&>(__t); }
template<typename t>
void copy(t* begin,t* end,t* to){
    while(begin!=end){
        *(begin++)=*(to++);
    }
}
template<typename t>
void fill(t* begin,t* end,t val){
    while(begin!=end){
        *(begin++)=val;
    }
}

template<typename t>
void set(t& data,::remove_all___v<t> val,int begin,int end){
    for(int i = begin;i < end; i++){
        data[i]=val;
    }
}
#endif