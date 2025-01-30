#ifndef AZZR_CONVERT
#define AZZR_CONVERT
#include <stdlib.h>
#include <string.h>
char* get_string(const char* str){
    char* a = (char*)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(a,str);
    return a;
}
#endif