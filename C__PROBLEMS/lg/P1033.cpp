#include <bits/stdc++.h>
using namespace std;
double v_a,v_b;double H,S,V,L,K;int n;
/*
d=0.5*g*t^2
t=sqrt(d/(0.5*g))
=sqrt(d/5)
*/
void calc(){
    v_a=sqrt(H/5.0);//to the bottom
    v_b=sqrt((H-K)/5.0);//to the top
}
int main(){
    cin >> H >> S >> V >> L >> K >> n;
/*
这个球落到车上:
经过v_b秒后,落在车的前面或后面
经过v_a秒后,落在车的前面和后面
*/
/*
第一个被接受的:
S+L,v_b
最后一个:
S,v_a
*/
    calc();
    int s = S+L-(v_b*V);
    int e = S-(v_a*V);
    s = min(s,n);
    e = max(e,0);
    cout << s - e;
}