#include <stdio.h>
#include <stdlib.h>
#include "cmd_read.c"
#include <vector>
class file{
    public:
    FILE* f = nullptr;
    private:
    class str_err {
        public:
        const char* message;
        str_err(const char* msg) : message(msg) {}
        const char* what() {
            return message;
        }
    };
    //specify for file
    //为此类专门改造
    enum FCASE_FLAGS{
        CR           = -160,
        LF           = -161,
        CR_ASCII     = '\r',
        LF_ASCII     = '\n',
    };
    int fcase(FILE* _Stream) {
        int c1;
        
        switch (c1=fgetc(_Stream)){
        case LF_ASCII:          return LF;
        case CR_ASCII:          return CR;
        
        default:
            return c1;
        }
    }
    int* lines;
    public:
    enum CUR_POSITION{
        BEGIN = SEEK_SET,//文件开头
        END = SEEK_END,//文件末尾
        NOW = SEEK_CUR,//当前位置
    };



    /**
     * 返回值：
     * 如果流是NULL， 则返回false， 否则返回true。
    */
    bool is_opening() {
        return f != nullptr;
    }

    /**
     * 返回值：
     * 如果流为NULL， 则返回true， 否则返回false。
    */
    bool is_close() {
        return f == nullptr;
    }

    /**
     * 返回值:
     * 如果读取操作已尝试读取超过文件的末尾， feof 函数将返回非零值；否则该函数返回
     * 0。 如果流指针为 NULL ，该函数会调用无效参数处理程序，如参数验证中所述。 如果允
     * 许执行继续， errno 将设置为 EINVAL ， feof 将返回 0。
    */
    //int feof(FILE *_File);

    /**
     * 返回值：
     * 如果流超过文件末尾，则返回true，否则返回false。
    */
    bool eof() {
        return feof(f) != 0;
    }
    
    /**
     * 返回值：
     * 如果未超过文件末尾，则返回true，否则返回false
    */
    bool neof() {
        return feof(f) == 0;
    }
    /**
     * 返回值：
     * 如果流为NULL或流超过文件末尾，返回true，否则返回false。
    */
    bool __eof() {
        return (f==nullptr||feof(f)!=0);
    }

    /**
     * 返回值：
     * 如果已成功关闭流，则 fclose 返回 0。 _fcloseall 返回已关闭流的总数。 这两个函数
     * 都返回 EOF ，表示出现错误
    */
    //int fclose(FILE *_File);

    /**
     * 返回值：
     * 如果已成功关闭流，则返回 true。否则返回false。
    */
    bool close() {
        if(f==nullptr)return true;
        if(fclose(f)==0){
            f=nullptr;
            return true;
        } else{
            return false;
        }
    }

    /**
     * 返回值：
     * 如果已成功关闭流，则返回true，否则抛出异常 "ERROR: CANNOT CLOSE"
    */
    bool __close() {
        if(f==nullptr)return true;
        if(fclose(f)==0){
            f = nullptr;
            return true;
        } else {
            throw str_err("ERROR: CANNOT CLOSE");
        }
    }

    /**
     * 返回值：
     * 设定文件指针位置，第一个参数为偏移量，第二个参数为从何处开始
     * 第二个参数默认为CUR_POSITION::NOW，为当前指针位置
     * 返回为void
    */
    void go_to(const int& offset,const int& _Pos = NOW) {
        fseek(f,offset,_Pos);
    }

    private:
    /**
     * 返回值：
     * 打开文件
    */
    bool  ____open(const char* path,const char* mode){
        return ((f=fopen(path,mode))!=nullptr);
    }

    /**
     * 返回值：
     * 打开文件
    */
    bool  ____wopen(const wchar_t* path,const wchar_t* mode){
        return ((f=_wfopen(path,mode))!=nullptr);
    }

    public:
    /**
     * 返回值：
     * 设定打开文件的路径，如果成功打开，返回true，
     * 否则返回false
    */
    bool open(const char* path,const char* mode) {
        if(is_opening()){
            __close();
        }
        if(____open(path,mode)){
            return true;
        } else {
            return false;
        }
    }

    /**
     * 返回值：
     * 设定打开文件的路径，如果成功打开，返回true，
     * 否则抛出异常 "ERROR: CANNOT OPEN"
    */
    bool __open(const char* path,const char* mode) {
        if(is_opening()){
            __close();
        }
        if(____open(path,mode)){
            return true;
        } else {
            throw str_err("ERROR: CANNOT OPEN");
        }
    }

    /**
     * 返回值：
     * 设定打开文件的路径，如果成功打开，返回true，
     * 否则返回false
    */
    bool wopen(const wchar_t* path,const wchar_t* mode) {
        if(is_opening()){
            __close();
        }
        if(____wopen(path,mode)){
            return true;
        } else {
            return false;
        }
    }

    /**
     * 返回值：
     * 设定打开文件的路径，如果成功打开，返回true，
     * 否则抛出异常 "ERROR: CANNOT OPEN"
    */
    bool __wopen(const wchar_t* path,const wchar_t* mode) {
        if(is_opening()){
            __close();
        }
        if(____wopen(path,mode)){
            return true;
        } else {
            throw str_err("ERROR: CANNOT OPEN");
        }
    }











    /**
     * 返回值：
     * 参见private:int fcase();
    */
    int get() {
        return fcase(f);
    }

    /**
     * 
    */
    int init_lines(){
        int count = 0;

    }
};


file f;
int main(){
    f.open("font","r");
}