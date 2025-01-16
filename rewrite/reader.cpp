#include <stdio.h>
class reader{
    public:
    FILE* f;
    template<typename... Args>
    void read(const char* path,Args&... args){
        f = fopen(path,"rb");
        read_core(args...);
        fclose(f);
    }
    template<typename t,typename... Args>
    void read_core(t val,Args&... args){
        read_core(val);
        read_core(args...);
    }
    template<typename t>
    void read_core(t& val){
        unsigned char* p = (unsigned char*)&val;
        for(int i = 1; i <= sizeof(t); i++){
            *(p++) = (unsigned char)fgetc(f);
        }
    }
};