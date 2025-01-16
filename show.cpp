// #include <iostream>
// #include <string>
#include <stdio.h>
#include "rewrite\dbg.cpp"
using namespace std;
FILE* f;
void show_line(size_t l){
    char str[10000];
    while(l-->0){
        fgets(str,10000,f);
    }
    printf("%s",str);
}
void show_line(size_t b,size_t e){
    char str[10000];
    e -= b-1;
    while(b-->0){
        fgets(str,10000,f);
    }
    while(e-->0){
        printf("%s",str);
        fgets(str,10000,f);
    }
}
size_t stoi(char* p){
    size_t ans = 0;
    while(*p!='\0'){
        ans = ans * 10 + *(p++) - '0';
    }
    return ans;
}
int main(int argc,char** argv){
    if(argc < 3 || argc > 4){
        // return -1;
        throw str_err("TOO FEW OR TOO MUCH ARGS,ONLY \"PATH LINE1 [LINE2]\" IS ENGOUGH");
    }
    f = fopen(argv[1],"r");
    if(argc == 3){
        show_line(stoi(argv[2]));
    }
    if(argc == 4){
        show_line(stoi(argv[2]),stoi(argv[3]));
    }
    fclose(f);
}