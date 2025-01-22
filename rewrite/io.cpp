#ifndef AZZR_IO
#define AZZR_IO
#include <stdio.h>
class out {
public:
    inline __attribute__((__always_inline__)) void operator()(const size_t& v) {printf("%llu", (unsigned long long)v);}
    inline __attribute__((__always_inline__)) void operator()(const int& v) {printf("%d", v);}
    inline __attribute__((__always_inline__)) void operator()(const bool& v) {printf("%d", v);}
    inline __attribute__((__always_inline__)) void operator()(const char& c) {printf("%c", c);}
    inline __attribute__((__always_inline__)) void operator()(const char* str) {printf("%s", str);}
    inline __attribute__((__always_inline__)) void operator()(char* str) {printf("%s", str);}
    inline __attribute__((__always_inline__)) void operator()(const double& v) {printf("%lf", v);}
    inline __attribute__((__always_inline__)) out& operator<<(const size_t& v) {printf("%llu", (unsigned long long)v);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const int& v) {printf("%d", v);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const bool& v) {printf("%d", v);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const char& c) {printf("%c", c);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const char* str) {printf("%s", str);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(char* str) {printf("%s", str);return *this;}
    inline __attribute__((__always_inline__)) out& operator<<(const double& v) {printf("%lf", v);return *this;}
    /*FOR EVERY_TYPE*/template<typename _Tp>void operator+(_Tp v){operator()(v);}
};
#endif