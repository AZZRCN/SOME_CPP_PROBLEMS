//发烧,新冠所做抽象代码
#include <bits/stdc++.h>
using namespace std;
char uc(char Dest,char Key){
    int ans = 26+(Dest&0xDF)-(Key&0xDF);
    return (ans%26)+('A'|(Dest&0x20));
}
inline constexpr bool is_c(const unsigned char& c){
    return (unsigned)((c&0xDFU)-0x41U)<26U;
}
char Key[100];
int Key_len=0,Key_cur=0;
char c;
int main(){
    while((c=getchar())!='\n'){
        Key[Key_len++]=c;
    }

    while(is_c(c=getchar())){
        putchar(uc(c,Key[Key_cur++]));
        if(Key_cur==Key_len)Key_cur=0;
    }
}