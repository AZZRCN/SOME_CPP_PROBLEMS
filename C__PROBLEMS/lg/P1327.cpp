#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
template<typename t>
void sort(vector<t>&v){
    sort(v.begin(),v.end());
}
int main(){
    int n;
    cin >> n;
    int t;
    for(int i = 0; i < n; i++){
        cin>>t;
        v.push_back(make_pair(t,i));//读入
    }
    int ans = 0;
    sort(v);
    for(int i = 0; i < n; i++){
        while(v[i].second!=i){//这个位置的的人是错的
            swap(v[i],v[v[i].second]);//这个位置上的人和他原本位置上的人互换（赶回去）
            ans++;
        }
    }
    cout << ans;
}