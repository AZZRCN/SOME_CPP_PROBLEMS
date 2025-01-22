#ifndef AZZR_ALLOCTOR
#define AZZR_ALLOCTOR
// #include <stdlib.h>
#include "_stdlib.cpp"
// #include <stdexcpt.h>
#include "function_.cpp"
#include "io.cpp"
template<typename T>
class alloctor {
public:
    T* data = nullptr;
    size_t size = 0;
    size_t malloced_real = 0;

    void mal(size_t size) {
        if (size > malloced_real) {
            if (data != nullptr) {
                free(data);
            }
            data = (T*)malloc(size * sizeof(T));
            malloced_real = size;
        }
        this->size = size;
    }

    T* single() {
        return (T*)malloc(sizeof(T));
    }

    void f(T* mem) {
        if (mem == nullptr) {
            return;
        }
        free(mem);
    }

    void f() {
        f(data);
        size = 0;
        malloced_real = 0;
    }

    T& operator[](size_t pos) { return data[pos]; }

    void copy(T* src, size_t len) {
        if (len > size) {
            mal(len);
        }
        for (int i = 0; i < len; i++) {
            data[i] = src[i];
        }
    }

    void multi(size_t mul) { resize(size * mul); }

    void plus(size_t plu) { resize(size + plu); }

    void resize(size_t size) {
        if (size > malloced_real) {
            mal(size);
        } else {
            this->size = size;
        }
    }

    T* begin() { return data; }

    T* end() { return data + size; }

    void fill(const T& v) {
        const T* end_ = end();
        T* p = begin();
        while (p != end_) {
            *p = v;
            p++;
        }
    }

    ~alloctor() {
        free((void*)data);
        //析构不是细狗
        // printf("XIGOU!\n");
        size = 0;
        malloced_real = 0;
    }
};
// void copy_(t* src,size_t len = size){
//     for(int i = 0; i < len; i++){
//         data[i] = src[i];
//     }
// }
// void copy(t* src,size_t len){
//     if(len>size){
//         mal(len);
//     }
//     copy_(src,len);
// }
#endif