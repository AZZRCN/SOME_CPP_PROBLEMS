/**问题抽象化：
 * 在一个是1和-1的数组里
 * 找到最长的一段和为0的子序列
 * 并输出其长度
**/
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> pre;
int n;
int main(){
    bool t;
    cin>>n;
    v.resize(n+1);
    pre.resize(n+1);
    pre[0]=0;
    for(int i = 1; i <= n; i++){
        cin>>t;
        v[i]=t;
        pre[i] = pre[i-1]+((t)?(1):(-1));
    }

    unordered_map<int,int>low;
    unordered_map<int,int>high;
    unordered_map<int,int>count;

    for(int i = 0; i <= n; i++){
        if(low.find(pre[i])==low.end()){
            low.insert(make_pair(pre[i],i));
            count.insert(make_pair(pre[i],1));
        }
        else{
            if(count[pre[i]]==1){
                high.insert(make_pair(pre[i],i));
                count[pre[i]]=2;
            }
            else{
                high[pre[i]]=i;
            }
        }
    }
    int maxn = 0;
    for(pair<int,int> i: count){
        if(i.first==1){continue;}
        maxn = max(high[i.first]-low[i.first],maxn);
    }
    cout << maxn;
    return 0;
}
//AC!!!!!
//OGHHHHH
//2025第一次用洛谷
//2025年1月18日 15:42:50