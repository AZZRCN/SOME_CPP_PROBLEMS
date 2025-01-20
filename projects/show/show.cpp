#include <stdio.h>
using namespace std;
FILE* f;char str[10000];
/**
 * @name:show.cpp
*/
#define get() fgets(str,10000,f)
void show_line(size_t l){while(l-->0){get();}printf("%s",str);}
void show_line(size_t b,size_t e){if(b>e){return;}e -= b-1;while(b-->0){get();}
while(e-->0){printf("%s",str);get();}}
size_t stoi(char* p){size_t ans = 0;while(*p!='\0'){ans=ans*10+*(p++)-'0';}return ans;}
int main(int argc,char** argv){f = fopen(argv[1],"r");
    if(argc == 3){show_line(stoi(argv[2]));}
    if(argc == 4){show_line(stoi(argv[2]),stoi(argv[3]));}
    fclose(f);
}
/**
 * @name:show_hex.cpp
*/
#define fmt "%02X "
#define bin(x,fmt) {char*p = x;while(*p&&*p!='\n'){printf(fmt,(int)(*p++));}}
#define endl() {printf("\n");}
#define get() fgets(str,10000,f)
void show_line(size_t l){while(l-->0){get();}bin(str);}
void show_line(size_t b,size_t e){if(b>e){return;}e -= b-1;while(b-->0){get();}
while(e-->0){bin(str);endl();get();}}
size_t stoi(char* p){size_t ans = 0;while(*p!='\0'){ans=ans*10+*(p++)-'0';}return ans;}
int main(int argc,char** argv){f = fopen(argv[1],"r");
    if(argc == 3){show_line(stoi(argv[2]));}
    if(argc == 4){show_line(stoi(argv[2]),stoi(argv[3]));}
    fclose(f);
}
/**
 * @name:show_all.cpp
*/
#define fmt "%02X "
#define bin(x,fmt,type) {char*p = x;while(*p&&*p!='\n'){printf(fmt,(type)(*p++));}}
#define endl() {printf("\n");}
#define get() fgets(str,10000,f)
void show_line(size_t l){while(l-->0){get();}bin(str,"%02X ",int);endl();bin(str,"%c  ",char);endl();}
void show_line(size_t b,size_t e){if(b>e){return;}e -= b-1;
while(b-->0){get();}
while(e-->0){bin(str,"%02X ",int);endl();bin(str,"%c  ",char);endl();get();}}
size_t stoi(char* p){size_t ans = 0;while(*p!='\0'){ans=ans*10+*(p++)-'0';}return ans;}
int main(int argc,char** argv){
    f = fopen(argv[1],"r");
    if(argc == 3){show_line(stoi(argv[2]));}
    if(argc == 4){show_line(stoi(argv[2]),stoi(argv[3]));}
    fclose(f);
}