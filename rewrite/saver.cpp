#include <stdio.h>
class saver{
    public:
    FILE* f;
    template<typename... Args>
    void save(const char* path,Args... args){
        f = fopen(path,"wb");
        save_core(args...);
        fclose(f);
    }
    template<typename t,typename... Args>
    void save_core(t val,Args... args){
        save_core(val);
        save_core(args...);
    }
    template<typename t>
    void save_core(t val){
        char* p = (char*)&val;
        for(int i = 1; i <= sizeof(t); i++){
            fprintf(f,"%c",*(p++));
        }
    }
};