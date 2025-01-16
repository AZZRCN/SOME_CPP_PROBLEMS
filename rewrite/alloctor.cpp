#ifndef AZZR_ALLOCTOR
#define AZZR_ALLOCTOR
#include <stdlib.h>
#include <stdexcpt.h>
#include "function_.cpp"
#include "io.cpp"
template<typename t>
class alloctor{
    public:
    t* data = nullptr;
    size_t malloced = 0;
    t* old = nullptr;
    size_t old_size = 0;
    void pack(){
        old = data;
        old_size = malloced;
    }
    void mal(size_t size){
        data = (t*)malloc(size*sizeof(t));
        malloced = size;
    }
    t* single(){
        return (t*)malloc(sizeof(t));
    }
    void f(t* mem){
        if(mem == nullptr){
            return;
        }
        free(mem);
    }
    void f(){
        f(data);
        malloced = 0;
    }
    t& operator[](size_t pos){return data[pos];}
    void copy(t* src,size_t len){
        if(len>malloced){
            mal(len);
        }
        for(int i = 0; i < len; i++){
            data[i] = src[i];
        }
    }
    void multi(size_t mul){resize(malloced*mul);}
    void plus (size_t plu){resize(malloced+plu);}
    void resize(size_t size){
        pack();
        mal(size);
        if(old!=nullptr){
            copy(old,min(old_size,size));
            f(old);
        }
    }
    t* begin(){return data;}
    t* end(){return data+malloced;}
    void fill(const t& v){
        const t* end_ = end();
        t* p = begin();
        while(p!=end_){
            *p = v;
        }
    }
    ~alloctor(){
        free((void*)data);
        printf("XIGOU!\n");
        malloced = 0;
    }
};
// void copy_(t* src,size_t len = malloced){
//     for(int i = 0; i < len; i++){
//         data[i] = src[i];
//     }
// }
// void copy(t* src,size_t len){
//     if(len>malloced){
//         mal(len);
//     }
//     copy_(src,len);
// }
#endif