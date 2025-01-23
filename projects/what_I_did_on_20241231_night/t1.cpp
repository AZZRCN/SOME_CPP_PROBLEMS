#include <bits/stdc++.h>
using namespace std;
char buf[100];
int main(){
    string bu = "FONT_BRIGHT\\A";
    FILE* f=fopen("font","r");
    for(int i = 0; i < 26; i++){
        bu.back() = 'A'+i;
        FILE* f2=fopen(bu.c_str(),"w");
        for(int j = 1; j<=6; j++){
            fgets(buf,100,f);
            fputs(buf,f2);
        }
        fclose(f2);
    }
    fclose(f);
}