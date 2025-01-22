#include <iostream>
//speeded 2024年8月14日
unsigned long long gcd(unsigned long long L, unsigned long long R) {
    unsigned long long lgo = 0;
    while (L ^ R) {
        if (!((L | R) & 1)) { L >>= 1; R >>= 1; lgo++; continue; }
        if (!(L & 1)) { L >>= 1; continue; }
        if (!(R & 1)) { R >>= 1; continue; }
        if (L < R) { R -= L; }
        else { L -= R; }
    }
    return std::max(L, R) << lgo;
}
/*
#define ull unsigned long long
ull _gcd(ull L, ull R) {
    ull lgo = 0;
    while (L != R) {
        if (!((L & 1) | (R & 1))) {
            L >>= 1;
            R >>= 1;
            lgo++;
            continue;
        }
        if (!(L & 1)) {
            L >>= 1;
            continue;
        }
        if (!(R & 1)) {
            R >>= 1;
            continue;
        }
        if (L < R) { std::swap(L, R); }
        L -= R;
    }
    if (L < R) { std::swap(L, R); }
    return L << lgo;
}
*/
//fixed
/*
#define ull unsigned long long
ull gcd(ull L, ull R){
    ull lgo = 0;
    while(L!=R && L != 0 && R != 0){
        if(!((L&1)|(R&1))){
            L >>=1;
            R>>=1;
            lgo++;
            continue;
        }
        if(!(L&1)){
            L>>=1;
            continue;
        }
        if(!(R&1)){
            R>>=1;
            continue;
        }
        if(L<R){swap(L,R);}
        L-=R;
    }
    if(L<R){swap(L,R);}
    return L<<lgo;
}
*/
//压行&&fixed
/*
#define ull unsigned long long
ull gcd(ull L,ull R){ull lgo=0;while(L!=R&&L!=0&&R!=0){if\
(!((L&1)|(R&1))){L>>=1;R>>=1;lgo++;continue;}if(!(L&1)){L\
>>=1;continue;}if(!(R&1)){R>>=1;continue;}if(L<R){swap(\
L,R);}L-=R;}if(L<R){swap(L,R);}return L<<lgo;}
*/
//例题:P4057
/*
int main(int argc, char const* argv[])
{
    ull a, b, c, lab;
    cin >> a >> b >> c;
    lab = a * b / _gcd(a, b);
    cout << lab * c / _gcd(lab, c);
    return 0;
}
*/