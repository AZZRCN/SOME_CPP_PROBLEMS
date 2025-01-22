#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kgcd(int x,int y){
    if(!x)return y;
    if(!y)return x;
    if(!((x&1)|(y&1))){
        return kgcd(x>>1,y>>1)<<1;
    } else if(!(x&1)){
        return kgcd(x>>1,y);
    } else if(!(y&1)){
        return kgcd(x,y>>1);
    } else {
        return kgcd(abs(x-y),min(x,y));
    }
}
// inline int upper(int n,int mod){
//     return 
//         // ((
//         ((n-1)%mod)
//         // +mod)%mod)
//     +1;
// }
int gcd(vector<int> n){
    sort(n.begin(),n.end(),[](int& x,int& y){return (x=abs(x))<(y=abs(y));});
    int carry = n.front();
    for(int i = 1; i < n.size();i++){
        if(carry==1)break;
        carry = ::kgcd(n[i],carry);
    }
    ret:
    return carry;
}
int main(){
    vector<int> v;
    int n;
    cin >> n;
    int t;
    while(n-->0){
        cin >> t;
        v.push_back(t);
    }
    cout << gcd(v);
}