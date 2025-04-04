#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        return a.second > b.second;
    }
};
//无数据限制
template<typename COMPARE>
class order{
    private:
    priority_queue<pair<int,int>,vector<pair<int,int>>,COMPARE>pq;
    unordered_set<int> s;
    public:
    void push(const int& _val,const int& flag){
        pq.push(make_pair(_val,flag));
        s.insert(_val);
    }
    void pop(){
        if(!s.empty()){
            s.erase(pq.top().first);
            pq.pop();
        }
    }
    bool contain(const int& _val){
        return s.find(_val) != s.end();
    }
    int size(){
        return s.size();
    }
};
order<cmp> o;
int main(){
    int m,n;
    cin >> m >> n;
    int t;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> t;
        if(o.contain(t)==false){
            if(o.size()==m){
                o.pop();
            }
            o.push(t,i);
            ans++;
        }
    }
    cout << ans;
}