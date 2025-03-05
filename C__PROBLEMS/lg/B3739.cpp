#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
template<typename _Tp,typename Func,typename After_Func>
int count_if(_Tp* arr,int length,After_Func After,Func _Cond){
    ull count = 0;
    while(--length>=0&&After(arr[length]));
    while(length>=0){
        if(_Cond(arr[length--])){
            count++;
        }
    }
    return count;
}
int a[100],b[100],c;
int main(){
    r(a,100);
    scanf("%d",&c);
    qpow<100,100>(a,c,b);
    cout <<
    count_if(b,100,[&](int x){return x==0;},[&](int x){return x%2==1;})-
    count_if(b,100,[&](int x){return x==0;},[&](int x){return x%2==0;});
}
//2025年3月2日 01:53:27