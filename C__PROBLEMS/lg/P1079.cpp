//发烧,新冠所做抽象代码
#include <bits/stdc++.h>
using namespace std;
char uc(char Dest,char Key){
    int ans = 26+(Dest&0xDF)-(Key&0xDF);
    return (ans%26)+('A'|(Dest&0x20));
}
int main(){
    string Dest,Key;
    cin >> Key >> Dest;
    const int k = Key.size();
    for(int i = 0; i < Dest.size(); i++){
        printf("%c",uc(Dest[i],Key[i%k]));
    }
}