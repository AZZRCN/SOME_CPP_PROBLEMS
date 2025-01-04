#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#ifndef NULL
#define NULL 0
#endif
#ifndef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
// template<int mod = 10>
// class N{
//     public:
//     vector<unsigned char> data;
//     bool is_palindrome(void){
//         if(data.size()==0){/* throw out_of_range("No data!");//strict*/return true;}
//         int l = 0,r = data.size()-1;
//         while(r>l){if(data[l++]!=data[r--]){return false;}};
//         return true;
//     }
//     void operator=(const std::initializer_list<unsigned char>&l){
//         //Oh ,shit ,it seems that the user won't reverse it;
//         // reverse(l.begin(),l.end());
//         // data.operator=(l);
//         if(l.size()==0){data.clear();data.push_back(0);}
//         else{data = l;reverse(data.begin(),data.end());}
//     }
//     N<mod>& operator+=(const N<mod>& o){
//         const int l_ = data.size(), r_ = o.data.size();
//         bool l__ = true,r__ = true;int carry = 0;
//         for(int i = 0; i < l_ || i < r_ || carry; i++){
//             if(i==l_){l__=false;}if(i==r_){r__=false;}
//             if(i==data.size()){data.push_back(0);}
//             if(l__){carry+=data[i];}if(r__){carry+=o.data[i];}
//             data[i]=carry%mod;carry/=mod;
//         }
//         return *this;
//     }
//     N<mod>& operator=(size_t x){data.clear();do{data.push_back(x%mod);x/=mod;}while(x);return*this;}
//     N<mod>& operator=(const N<mod>& x){data = x.data;return *this;}
//     void reverse(void){::reverse(data.begin(),data.end());}
//     N<mod> reverse_(void){N<mod> n = *this;::reverse(n.data.begin(),n.data.end());return n;}
//     __forceinline vector<unsigned char>::iterator begin(){return data.begin();}
//     __forceinline vector<unsigned char>::iterator end(){return data.end();}
//     void print(char end = '\n'){
//         for_each(data.rbegin(),data.rend(),[](const unsigned char x){putchar(x+'0');});
//         putchar('\n');
//     }
// };
//ONLY mod = 1_10 && 16
class N{
    public:
    #define check(x) if(x.mod!=mod){throw invalid_argument("MOD != MOD");};
    vector<unsigned char> data;
    int mod;
    bool is_palindrome(void){
        if(data.size()==0){/* throw out_of_range("No data!");//strict*/return true;}
        int l = 0,r = data.size()-1;
        while(r>l){if(data[l++]!=data[r--]){return false;}};
        return true;
    }
    void operator=(const std::initializer_list<unsigned char>&l){
        //Oh ,shit ,it seems that the user won't reverse it;
        // reverse(l.begin(),l.end());
        // data.operator=(l);
        if(l.size()==0){data.clear();data.push_back(0);}
        else{data = l;::reverse(data.begin(),data.end());}
    }
    N(const int x){mod = x;}
    N(void){mod = 10;}
    N& operator+=(const N& o){
        check(o);
        const int l_ = data.size(), r_ = o.data.size();
        bool l__ = true,r__ = true;int carry = 0;
        for(int i = 0; i < l_ || i < r_ || carry; i++){
            if(i==l_){l__=false;}if(i==r_){r__=false;}
            if(i==data.size()){data.push_back(0);}
            if(l__){carry+=data[i];}if(r__){carry+=o.data[i];}
            data[i]=carry%mod;carry/=mod;
        }
        return *this;
    }
    //Dec
    N& operator=(size_t x){data.clear();do{data.push_back(x%mod);x/=mod;}while(x);return*this;}
    N& operator=(const N& x){check(x);data = x.data;return *this;}
    void reverse(void){::reverse(data.begin(),data.end());}
    N reverse_(void){N n = *this;::reverse(n.data.begin(),n.data.end());return n;}
    __forceinline vector<unsigned char>::iterator begin(){return data.begin();}
    __forceinline vector<unsigned char>::iterator end(){return data.end();}
    void print(char end = '\n'){
        for_each(data.rbegin(),data.rend(),[&](const unsigned char x){putchar(convert_dec_hex(x));});
        putchar('\n');
    }
    inline bool is_digit(char c){
        return (c>='0')&&(c<='9');
    }
    inline bool is_hex(char c){
        return is_digit(c)||((c>='A')&&(c<='F'));
    }
    inline int convert_hex_dec(char c){
        if(is_digit(c)){
            return c-'0';
        }
        return c-'A'+10;
    }
    inline int convert_dec_dec(char c){
        return c-'0';
    }
    inline char convert_dec_hex(int n){
        if(n<10){
            return n+'0';
        }
        return n-10+'A';
    }
    void get_dec(){
        data.clear();char ch = getchar();
        while (!is_digit(ch)) {ch = getchar();}
        while (is_digit(ch)) {data.push_back(convert_dec_dec(ch));ch = getchar();}
        reverse();
    }
    void get_hex(){
        data.clear();char ch = getchar();
        while (!is_hex(ch)) {ch = getchar();}
        while (is_hex(ch)) {data.push_back(convert_hex_dec(ch));ch = getchar();}
        reverse();
    }
    void get(){
        if(mod == 16){
            get_hex();
        }
        else{
            get_dec();
        }
    }
    void get_dec(const string&str){
        data.clear();int i = 0;
        while (!is_digit(str[i])) {i++;}
        while (is_digit(str[i])) {data.push_back(convert_dec_dec(str[i]));i++;}
        reverse();
    }
    void get_hex(const string&str){
        data.clear();int i = 0;
        while (!is_hex(str[i])) {i++;}
        while (is_hex(str[i])) {data.push_back(convert_hex_dec(str[i]));i++;}
        reverse();
    }
    void get(const string&str){
        if(mod == 16){
            get_hex(str);
        }
        else{
            get_dec(str);
        }
    }
};
N a;
int main(){
    cin >> a.mod;
    a.get();
    for(int i = 1; i <= 31; i++){
        a += a.reverse_();
        if(a.is_palindrome()){
            printf("STEP=%d",i);
            a.print();
            return 0;
        }
    }
    printf("Impossible!");
    // for(int i:a.data){
    //     printf("%d ",i);
    // }
}