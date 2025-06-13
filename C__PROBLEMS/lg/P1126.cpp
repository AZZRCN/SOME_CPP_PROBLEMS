/*
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 S
*/
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;using vvi = vector<vi>;using pos = pair<int,int>;using v_pos = array<int,4>;
enum{NORTH=0,EAST=1,SOUTH=2,WEST=3};vector<vector<v_pos>> vp;vvi mp;const pos moves[] = {{-1,0},{0,1},{1,0},{0,-1}};
//对于{x,y}来说,占据的是
//{x-1,y-1},{x,y-1},{x-1,y},{x,y}
int N,M;
queue<pos> wait;
pos add(const pos& a,const pos& b){
    return {a.first+b.first,a.second+b.second};
}
bool valid(const pos& p){
    return !(
p.first<=0 ||
p.first>=N ||
p.second<=0||
p.second>=M
        )&&!(
mp[p.first-1][p.second-1]||
mp[p.first  ][p.second-1]||
mp[p.first-1][p.second  ]||
mp[p.first  ][p.second  ]
    );
}
template<typename t>t Mmin(const t& first,const t& second){return min(first,second);}
template<typename t,typename ...Rest>t Mmin(const t& first,const t& second,Rest... args){return Mmin(min(first,second),args...);}
void update(const pos& p){
    v_pos& _p = vp[p.first][p.second];
    pos t;
    for(int i = 0; i < 4; i++){
        _p[i] = Mmin(_p[(i+1)%4]+1,_p[(i+3)%4]+1,_p[i],_p[(i+2)%4]+2);
    }
    for(int i = 0; i < 4; i++){
        t = p;
        for(int j = 1; j <= 3; j++){
            t = add(moves[i],t);
            if(!valid(t))break;
            if(vp[t.first][t.second][i]>vp[p.first][p.second][i]+1){
                vp[t.first][t.second][i] = vp[p.first][p.second][i]+1;
                wait.push(t);
            }
        }
    }
    
}
void BFS(int a,int b,int c,int d,char e){
    switch (e)
    {
    case 'S':
        vp[a][b][SOUTH] = 0;
        break;
    case 'N':
        vp[a][b][NORTH] = 0;
        break;
    case 'E':
        vp[a][b][EAST] = 0;
        break;
    case 'W':
        vp[a][b][WEST] = 0;
        break;
    default:
        break;
    }
    wait.push({a,b});
    while(!wait.empty()){
        update(wait.front());
        wait.pop();
    }
}
int main(){
    freopen(__FILE__,"r",stdin);
    getchar();getchar();
    cin >> N >> M;
    mp.resize(N,vi(M,0));
    vp.resize(N,vector<v_pos>(M,{0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f}));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> mp[i][j];
        }
    }
    int sx,sy,ex,ey;
    char sf;
    cin >> sx >> sy >> ex >> ey >> sf;
    // sx--;sy--;ex--;ey--;
    BFS(sx,sy,ex,ey,sf);
    cout << Mmin(vp[ex][ey][0],vp[ex][ey][1],vp[ex][ey][2],vp[ex][ey][3]);
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         printf("%6d\t",Mmin(vp[i][j][0],vp[i][j][1],vp[i][j][2],vp[i][j][3],999999));
    //     }
    //     printf("\n");
    // }
}