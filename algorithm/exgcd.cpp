//扩展欧几里得算法
//a,b,&x,&y
//ax+by=gcd(a,b)
//x,y为解
void exgcd(const int&a,const int&b,int& x,int& y) {
    if(b == 0){x=1;y=0;return;}
    exgcd(b,a%b,x,y);
    const int tx = x;
    x = y;
    y = tx-a/b*y;
}
/*
//LUOGU //P1082
#include <iostream>
using namespace std;
int main() {
    int x=0,y=0,a,b;
    cin >> a >> b;
    exgcd(a,b,x,y);
    cout << (x+b)%b;
    return 0;
}
*/