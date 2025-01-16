#ifndef AZZR_IO
#define AZZR_IO

#include <stdio.h>
#include <stdarg.h> // 用于可变参数函数

class out {
public:
    const char* split = nullptr;
    const char* mem_print_split = "======";
    // operator() 用于处理不同的数据类型
    inline __attribute__((__always_inline__)) void operator()(const size_t& v) {printf("%llu", (unsigned long long)v);}
    inline __attribute__((__always_inline__)) void operator()(const int& v) {printf("%d", v);}
    inline __attribute__((__always_inline__)) void operator()(const char& c) {printf("%c", c);}
    inline __attribute__((__always_inline__)) void operator()(const char* str) {printf("%s", str);}
    inline __attribute__((__always_inline__)) void operator()(const double& v) {printf("%lf", v);}

    // 重写 operator<<，将调用委托给 operator()
    inline __attribute__((__always_inline__)) out& operator<<(const size_t& v) {printf("%llu", (unsigned long long)v);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const int& v) {printf("%d", v);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const char& c) {printf("%c", c);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const char* str) {printf("%s", str);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const double& v) {printf("%lf", v);return *this;}

    // fls 方法
    void fls() {
        fflush(stdout);
    }
    template<typename t>
    void mem_print(t x){
        unsigned char* p = (unsigned char*)&x;
        for(int i = 1; i <= sizeof(t); i++){
            printf("%02X",(int)*(p++));
        }
    }
    // template<typename T>
    // void memory_print_arr_core(const T* arr, const size_t& size){
    //     for (size_t i = 0; i < size; ++i) {
    //         printf("%p %zu | ", static_cast<const void*>(&arr[i]), i); // 输出地址和下标
    //         operator()(arr[i]); // 使用 operator() 打印当前元素的值
    //         printf("\n");
    //     }
    // }
    template<typename T>
    void memory_print_p_core(const T* begin, const T* end){
        size_t count = 0;
        for (T* i = (T*)begin; i != end; ++i) {
            printf("%p %zu | ", static_cast<const void*>(i), (count++)); // 输出地址和下标
            operator()(*i); // 使用 operator() 打印当前元素的值
            printf("\n");
        }
    }
    // void memory_print_helper(void){
    //     puts(mem_print_split);
    // }
    // template<typename first,typename second,typename... Args>
    // void memory_print_helper(first a,second b,Args... args){
    //     puts(mem_print_split);
    //     memory_print_no_text(a,b);
    //     memory_print_helper(args...);
    // }
    // template<typename T>void memory_print(const T* arr, const size_t& size) {
    //     puts(mem_print_split);memory_print_arr_core(arr,size);
    //     puts(mem_print_split);
    // }
    // template<typename T>void memory_print(const T* begin, const T* end) {
    //     puts(mem_print_split);memory_print_p_core(begin,end);
    //     puts(mem_print_split);
    // }
    // template<typename T>
    // void memory_print_no_text(const T* arr, const size_t& size) {
    //     memory_print_arr_core(arr,size);}
    // template<typename T>
    // void memory_print_no_text(const T* begin, const T* end) {
    //     memory_print_p_core(begin,end);}
    //Pairs of args
    // template<typename... Args>
    // void memory_print_pair_args(Args... args){
    //     static_assert(sizeof...(args)%2==0,"even number of args");
    //     memory_print_helper(args...);
    // }
    void operator()(void){
        //Do nothing
    }
    template<typename Ty,typename... Args>
    /*inline __attribute__((__always_inline__)) */
    void operator()(Ty first,Args... args){
        operator()(first);
        if(split != nullptr){operator()(split);}
        operator()(args...);
    }
    //Only works when you use operator() and at least two arg
    void set_split(const char* spl){
        split = spl;
    }
    void set_split(void){
        split = nullptr;
    }
};

#endif // AZZR_IO
// out& operator()(const char* fmt, ...) {
//     va_list l;
//     va_start(l, fmt);
//     __mingw_vfprintf(stdout, fmt, l);
//     va_end(l);
//     return *this;
// }