#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool be(const string& Dist,const string& Src){
        if(Dist.size()>Src.size())return false;
        for(int i = 0; i < Dist.size(); i++){
            if(Dist[i]!=Src[i])return false;
        }
        return true;
    }
    int countPrefixes(const vector<string>& words, const string& s) {
        int ans = 0;
        for_each(words.begin(),words.end(),[&](const string& x){
            if(be(x,s)){ans++;}
            });
        return ans;
    }
};
Solution s;
int main(){
    cout << s.countPrefixes({"a","a"},"abc");
}