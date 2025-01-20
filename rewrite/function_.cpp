#ifndef AZZR_FUNCTION
#define AZZR_FUNCTION
#include <crtdefs.h>
constexpr inline
size_t min(const size_t& a,const size_t& b){
    return ((a<b)?(a):(b));
}
// template<typename t1,typename t2>
// class less{
//     constexpr bool operator()(const t1& x,const t2& y){
//         return x < y;
//     }
// };
template<typename t>
class less{
    constexpr bool operator()(const t& x,const t& y){
        return x < y;
    }
};
template<typename t>
  inline void
  swap(t&__x, t&__y) noexcept
  {
    t __tmp = __x;
    __x = __y;
    __y = __tmp;
  }
#endif