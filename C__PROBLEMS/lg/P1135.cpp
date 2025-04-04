#include <bits/stdc++.h>
using namespace std;
bool vis[205];
unsigned short cost[205];
unsigned short jmp[205];
unsigned short N,A,B,pos;
queue<int> poss;
int main(){
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i ++){
        cin >> jmp[i];
    }
    poss.push(A);
    vis[A]=1;
    while(!poss.empty()&&!vis[B]){
        pos = poss.front();
        poss.pop();
        if(pos+jmp[pos]<=N&&!vis[pos+jmp[pos]]){
            vis[pos+jmp[pos]]=1;
            poss.push(pos+jmp[pos]);
            cost[pos+jmp[pos]]=cost[pos]+1;
        }
        if(pos-jmp[pos]>=1&&!vis[pos-jmp[pos]]){
            vis[pos-jmp[pos]]=1;
            poss.push(pos-jmp[pos]);
            cost[pos-jmp[pos]]=cost[pos]+1;
        }
    }
    if(!vis[B]){
        cout << -1;
    }
    else{
        cout << cost[B];
    }
}