#include <bits/stdc++.h>
using namespace std;
void outv(const vector<int>& v){
    for(int i : v){printf("%d ",i);}
}
class Solution {
public:
    //给定一堆0,1
    //求越过1次1得到的最长0长度
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> v;//0101...
        int _ = 0;//count of 0
        int t = 0;
        bool flag = 0;
        bool is_head_one = true;
        for(int i = 0; i < s.size(); i++){
            if(is_head_one&&s[i]=='1'){continue;}
            is_head_one = false;
            if(s[i]-'0'==flag){//和上一个一样
                t++;
            }
            else{//不一样
                if(flag == 0){
                    v.push_back(t);
                    t=1;
                    _++;
                    flag = 1;
                }
                else{
                    v.push_back(t);
                    t = 1;
                    flag = 0;
                }
            }
        }
        if(flag == 0 && t){
            v.push_back(t);
            _++;
        }
        int ans = 0;
        for(int i = 0; i < _-1; i++){
            ans = max(v[i*2]+v[i*2+1]+v[i*2+2],ans);
        }
        if(_ == 1){
            ans = v[0];
        }
        // outv(v);
        return ans;
    }
};
Solution s;
int main(){
    cout << s.maxActiveSectionsAfterTrade("1000100");
}