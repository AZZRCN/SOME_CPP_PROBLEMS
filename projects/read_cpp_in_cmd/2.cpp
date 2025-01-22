#include <iostream>
#include <fstream>
#include <windows.h>
#define black 0
#define blue 1
#define green 2
#define light_green 3
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define gray 8
#define light_blue 9
#define pale_green 10
#define pale_light_green 11
#define pale_red 12
#define pale_purple 13
#define pale_yellow 14
#define light_white 15
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int now_color = 7;
//print const char* with color
void CPRS(const char* s, int color/*<=255*/)
{
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
printf(s);
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void SetC(int front_color,int back_color){
    now_color = (back_color << 4) | front_color;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | now_color);
}
//reset the color to now_color
void RC(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | now_color);
}
//color clean but with sign
void CleanC(){
    now_color = 7;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | now_color);
}
//Null color clean
void NC(){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void CCH(char c,int color){
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    putchar(c);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
bool Has(string str,int pos, string _catch){
    return str.substr(pos, _catch.size()) == _catch;
}
int Next_pos(string str,int start_pos,char _catch){
    for(int i = start_pos; i < str.size(); i ++)
        if(str[i] == _catch)
            return i;
    return -1;
}
int DEC_len(int n)
{
    int r = 0;
    while(n)
    {
        n /= 10;
        r ++;
    }
    return r;
}
void __inline__ print(char c, int n)
{
    if(n>>31)
        return;
    while(n --)
        putchar(c);
}
bool ischar(char c){
    bool r = false;
    if(c >= 'a' and c <= 'z') r = true;
    if(c >= 'A' and c <= 'Z') r = true;
    if(c >= '0' and c <= '9') r = true;
    return r;
}
int main(int argc, char** argv){
    if(argc != 2){return 0;}
    // FILE* file = fopen(argv[1], "r");
    int space_next = 0;
    unsigned int deep = 0;
    fstream fin(argv[1]);
    string str;
    int n = 0;
    while(getline(fin,str)){
        //SetC((n++)&0XF,0);
        n++;
        NC();
        printf("[line_");
        print(' ',5 - DEC_len(n));
        printf("%d",n);
        printf("]");
        RC();
        space_next = 0;
        while(str[space_next] == ' '){
            putchar(' ');
            space_next++;
        }
        for(int i = space_next; i < str.length(); i++){
            if(str[i] == '/' and str[i+1] == '/'){
                SetC(green,0);
                for(int j = i; j< str.length(); j++){
                    putchar(str[j]);
                }
                i = str.length();
                continue;
            }
            if(str[i] == '\\'){
                putchar('\\');
                putchar(str[i+1]);
                i++;
                continue;
            }
            if(str[i] == '\''){
                bool BN = false;//for break
                SetC(pale_yellow,0);
                putchar('\'');
                bool down_2 = false;
                for(int j = i+1; j < str.length(); j++){
                    if(str[j] == '\\'){
                        putchar(str[j]);
                        if(j+1<str.length())
                        {
                            putchar(str[j+1]);
                        }
                        j++;
                        continue;
                    }
                    putchar(str[j]);
                    if(str[j] == '\''){
                        i = j;
                        BN = true;
                        j = str.length();
                    }
                }
                while(not BN and getline(fin,str)){
                    n++;
                    putchar('\n');
                    NC();
                    printf("[line_");
                    print(' ',5 - DEC_len(n));
                    printf("%d]",n);
                    RC();
                    for(int j = 0; j < str.length(); j++){
                        if(str[j] == '\'' and str[j-1] != '\\'){
                            putchar('\'');
                            i = j;
                            BN = true;
                            j = str.length();
                        }
                        else{
                            putchar(str[j]);
                        }
                    }
                }
                // while(not n;){
                //     for(int k = 0 ; k < str.length(); k++)
                // }
                continue;
            }
            if(str[i] == '\"') {
                bool BN = false;//for break
                SetC(pale_yellow,0);
                putchar('\"');
                for(int j = i+1; j < str.length(); j++){
                    if(str[j] == '\\'){
                        putchar(str[j]);
                        if(j+1<str.length())
                        {
                            putchar(str[j+1]);
                        }
                        j++;
                        continue;
                    }
                    if(str[j] == '\"'){
                        putchar('\"');
                        i = j;
                        BN = true;
                        j = str.length();
                    }
                    else{
                        putchar(str[j]);
                    }
                }
                while(not BN and getline(fin,str)){
                    n++;
                    putchar('\n');
                    NC();
                    printf("[line_");
                    print(' ',5 - DEC_len(n));
                    printf("%d",n);
                    printf("]");
                    RC();
                    for(int j = 0; j < str.length(); j++){
                        if(str[j] == '\"' and str[j-1] != '\\'){
                            putchar('\"');
                            i = j;
                            BN = true;
                            j = str.length();
                        }
                        else{
                            putchar(str[j]);
                        }
                    }
                }
                // while(not n;){
                //     for(int k = 0 ; k < str.length(); k++)
                // }
                continue;
            }
            if(str[i] == '{' or str[i] == '[' or str[i] == '(') {
                deep++;
                if(deep%3 == 1){
                    SetC(yellow,0);
                }
                if(deep%3 == 2){
                    SetC(purple,0);
                }
                if(deep%3 == 0){
                    SetC(blue,0);
                }
                putchar(str[i]);
                continue;
            }
            if(str[i] == '}' or str[i] == ']' or str[i] == ')') {
                if(deep%3 == 1){
                    SetC(yellow,0);
                }
                if(deep%3 == 2){
                    SetC(purple,0);
                }
                if(deep%3 == 0){
                    SetC(blue,0);
                }
                deep--;
                putchar(str[i]);
                continue;
            }
            if(str[i] == ';'){
                CPRS(";",red);
                continue;
            }
            if(str[i] == 'a' and str[i+1] == 'n' and str[i+2] == 'd' and not ischar(str[i-1]) and not ischar(str[i+3])){
                CPRS("and",red);
                i += 2;
                continue;
            }
            if(str[i] == 'o' and str[i+1] == 'r' and not ischar(str[i-1]) and not ischar(str[i+2])){
                CPRS("or",red);
                i++;
                continue;
            }
            if(str[i] == '|' or str[i] == '&' or str[i] == '^' or str[i] == '~'){
                CCH(str[i],blue);
                continue;
            }
            CleanC();
            putchar(str[i]);
        }
        printf("\n");
        //cout << str << endl;
    }
    CleanC();
}