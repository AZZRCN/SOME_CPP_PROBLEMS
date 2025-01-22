#include <stdio.h>
#include "type_trait.cpp"
class saver{
    public:
FILE* f;
__forceinline void open(const char*path){f=fopen(path,"wb");}
__forceinline void close(){if(f!=nullptr){fclose(f);f=nullptr;}}
template<typename...Args>void save(const char*path,Args...args)
{open(path);save_core(args...);close();}
template<typename t1,typename t2,typename...Args>
void save_core(t1 a,t2 b,Args...args){
if(is_pointer<t1>::value||is_array<t1>::value){save_core_p(a,b);save_core(args...);}
else{save_core_val(a);save_core(b,args...);}}
template<typename _Tp>__forceinline void save_core(_Tp v){save_core_val(v);}
template<typename _Tp>void save_core_val(_Tp val)
{char*p=(char*)&val;for(int i=1;i<=sizeof(_Tp);i++){fprintf(f,"%c",*(p++));}}
template<typename _Tp>void save_core_p(_Tp*arr,size_t size)
{unsigned char*p=(unsigned char*)arr;for(int i=1;i<=size*sizeof(_Tp);i++){fprintf(f,"%c",*(p++));}}
__forceinline void save_core(void){/*Do nothing*/}
};