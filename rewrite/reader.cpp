#include <stdio.h>
// #include "type_trait.cpp"
class reader{
template<typename _Tp>struct remove_const{ typedef _Tp     type; };
template<typename _Tp>struct remove_const<_Tp const>{ typedef _Tp     type; };
template<typename _Tp>struct remove_volatile{ typedef _Tp     type; };
template<typename _Tp>struct remove_volatile<_Tp volatile>{ typedef _Tp     type; };
template<typename _Tp>struct remove_cv{typedef typename 
    remove_const<typename remove_volatile<_Tp>::type>::type type;};
template<typename _Tp, _Tp __v>
struct integral_constant
{
    static constexpr _Tp                  value = __v;
    typedef _Tp                           value_type;
    typedef integral_constant<_Tp, __v>   type;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};
typedef integral_constant<bool, true>     true_type;
typedef integral_constant<bool, false>    false_type;
template<typename>struct __is_pointer_helper: public false_type { };
template<typename _Tp>struct __is_pointer_helper<_Tp*>: public true_type { };
template<typename _Tp>struct is_pointer: public __is_pointer_helper<typename remove_cv<_Tp>::type>::type{ };
template<typename>struct is_array: public false_type { };
template<typename _Tp, size_t _Size>struct is_array<_Tp[_Size]>: public true_type { };
template<typename _Tp>struct is_array<_Tp[]>: public true_type { };
    public:
    FILE* f;
__forceinline void open(const char* path){f = fopen(path,"rb");}
__forceinline void close(){if(f!=nullptr){fclose(f);f=nullptr;}}
template<typename... Args>
void read(const char* path,Args&... args){open(path);read_core(args...);close();}
template<typename t1,typename t2,typename... Args>
// auto 
void read_core(t1& a,t2& b,Args&... args)
//  -> enable_if_t<no<is_const<t2>::value>>
    {
    if(is_pointer<t1>::value||is_array<t1>::value)
    {read_core_p(a,b);read_core(args...);}
    else{read_core_val(a);read_core(b,args...);}
}
template<typename t>__forceinline void read_core(t& v){read_core_val(v);}
template<typename t>void read_core_val(t& val){unsigned char* p = (unsigned char*)&val;
    for(int i=1;i<=sizeof(t);i++){*(p++)=(unsigned char)fgetc(f);}
}
template<typename t>void read_core_p(t arr,size_t size){unsigned char*p=(unsigned char*)arr;
    for(int i=1;i<=size*sizeof(remove_cv<t>);i++){*(p++)=(unsigned char)fgetc(f);}
}
__forceinline void read_core(void){/*Do nothing*/}
};