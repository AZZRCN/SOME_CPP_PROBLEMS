#ifndef AZZR_DEFINES
#define AZZR_DEFINES
#define Chongzai R"(如何重载自增自减\
Clock& operator++(),前置,没有形参\
Clock operator++(int),后置,形参int作为区分)"
#define err(cond) if(cond){throw str_err("Hit An Err Because condition " #cond);}
#define typeof(x) decltype(x)
template<typename t1,typename t2>
class pair;
class for_bitset_proxy;
class for_arr_dec;
#endif