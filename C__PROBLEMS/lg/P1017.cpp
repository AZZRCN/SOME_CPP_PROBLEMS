//-304 -20
#include <bits/stdc++.h>
using namespace std;
const char* c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";vector<char>o;
template<typename _Ty,typename _Out>void out(const _Ty& b,const _Ty& e,_Out& out){
    _Ty x = b;while(x!=e){out << *x;x++;}}
void re(){freopen(__FILE__,"r",stdin);getchar();getchar();}
int main(){
    // re();
    int n,R;
    cin >> n >> R;
    printf("%d=",n);
    do{
        // o.push_back(c[(n%R<0)?((n%R)-R):(n%R)]);
        // n = ((n%R<0)?((n/R)+1):(n/R));
        if(n%R<0){
            o.push_back(c[(n%R)-R]);
            n=(n/R)+1;
        }
        else{
            o.push_back(c[n%R]);
            n/=R;
        }
        /**
         * 参考题解第一篇：
         * 核心原理解释：
         * 其他地方仿照正常十进制操作；
         * c[n%10],
         * n/=10
         * 如果取模为负数，不符合0~R-1的范围要求
         * 那么将本次减去R，商加上1
         * 保证了范围符合，而且总的值不变
        */
    }while (n != 0);
    out(o.rbegin(),o.rend(),cout);
    printf("(base%d)",R);
}


/* */