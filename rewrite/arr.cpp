#ifndef AZZR_SIMPLE_ARR
#define AZZR_SIMPLE_ARR
#include"defines.cpp"
#include"function_.cpp"
template<typename t,unsigned long long size>
class arr{
    public:
    t data[size];
    t& operator[](unsigned long long pos){
        return data[pos];
    }
    arr(void){}
    t* begin(){
        return data;
    }
    t* end(){
        return data+size;
    }
    void set(const t& val){
        ::set(data,0,0,size);
    }
};
template<unsigned long long size>
class arr<for_arr_dec,size>:arr<int,size>{
    #define data arr::data
    public:
    void operator=(unsigned long long x){
        int cur = 0;
        while(x){
            data[cur++]=(x%10);
            x%=10;
        }
        ::set(data,0,cur,size);
    }
    void clear(){
        ::set(data,0,0,size);
    }
    #undef data
};
#endif