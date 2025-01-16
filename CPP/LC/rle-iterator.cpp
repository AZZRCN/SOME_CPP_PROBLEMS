#include <bits/stdc++.h>
using namespace std;
class RLEIterator {
public:
    vector<int> v;
    int i=0;
    RLEIterator(vector<int>& encoding) {
        v=encoding;
    }
    int next(int n) {
        int l = -1;
        while(n&&i<v.size()){
            if(n>=v[i]){
                l=v[i+1];
                n-=v[i];
                v[i]=0;
                i+=2;
            }
            else{
                l=v[i+1];
                v[i]-=n;
                n=0;
            }
        }
        return (n)?(-1):(l);
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */