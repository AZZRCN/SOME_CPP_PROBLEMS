#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(stack<int> ns,const int& tgt,vector<int> v){
        if(tgt==0){
            ans.push_back(v);
            return;
        }
        while(!ns.empty()){
            if(ns.top()<=tgt){
                v.push_back(ns.top());
                dfs(ns,tgt-ns.top(),v);
                v.pop_back();
            }
            ns.pop();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& ns, int tgt) {
        sort(ns.begin(),ns.end(),greater<int>());
        stack<int> s;
        for(int i : ns){
            s.push(i);
        }
        dfs(s,tgt,{});
        return ans;
    }
};