#include <bits/stdc++.h>
using namespace std;
bitset<200> bs;
template<size_t bs_size>
string bitset2str(bitset<bs_size> &bs){
    int cur = bs_size-1;//the cur of bs
    int carry;//JUST CARRY
    vector<int> v;//the ans
    int multi;//the multi works on the ans
    goto mainly;
    multiandplus:
    carry = bs[cur];
    for(int i = 0; carry||i<v.size(); i++){
        if(v.size()==i){
            v.push_back(0);
        }
        carry = v[i]*multi+carry;
        v[i] = carry%10;
        carry/=10;
    }
    goto back;
    mainly:
    for(;cur>=0;cur--){
        multi=2;
        //不是必要
        for(;cur&&bs[cur]==0&&multi!=1024;cur--,multi*=2);//works max  8 times
        //只是加速
        goto multiandplus;
        back:
        ;
    }
    //end
    string ans;
    const int p = v.size()-1;
    ans.resize(p+1);
    for(int i = 0; i <= p; i++){
        ans[p-i] = (v[i]|0x30);
    }
    return ans;
}
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        bs[i]=1;
    }
    cout << bitset2str(bs);
}