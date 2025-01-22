#include <bits/stdc++.h>
using namespace std;
class ATM {
public:
    vector<int> v;
    vector<int> c;
    vector<int> t;
    ATM() {
        // v.resize(5);
        v={0,0,0,0,0};
        c={20,50,100,200,500};
    }
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            v[i]+=banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount) {
        if((amount<50&&amount!=20)||amount%10){
            return {-1};
        }
        t={0,0,0,0,0};
        for(int i = 4; i >= 0; i--){
            int _t = min(v[i],amount/c[i]);
            t[i]+=_t;
            amount-=_t*c[i];
        }
        if(amount){
            return {-1};
        }
        for(int i = 0; i < 5; i++){
            v[i]-=t[i];
        }
        return t;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */