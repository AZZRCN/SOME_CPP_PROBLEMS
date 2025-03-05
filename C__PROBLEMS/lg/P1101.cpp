// #include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int x[8] = {0,1,1,1,0,-1,-1,-1};
const int y[8] = {1,1,0,-1,-1,-1,0,1};
char map[100][100];
bool valid[100][100];
int map_size;
string cat = "yizhong";
//find str "yizhong" in map
bool check(const int& __x, const int& __y, const int& cur) {
    int _x = __x;
    int _y = __y;
    if(_x+x[cur]*6>=map_size
    ||_x+x[cur]*6<0
    ||_y+y[cur]*6>=map_size
    ||_y+y[cur]*6<0) return false;
    for(int i=0;i<7;i++) {
        if(map[_x][_y]!=cat[i]) return false;
        _x+=x[cur];
        _y+=y[cur];
    }
    return true;
}
void mark(const int& __x, const int& __y, const int& cur) {
    int _x = __x;
    int _y = __y;
    for(int i=0;i<7;i++) {
        valid[_x][_y] = true;
        _x+=x[cur];
        _y+=y[cur];
    }
}
void _try(const int& __x, const int& __y) {
    // puts("HIT");
    for(int i=0;i<8;i++) {
        if(check(__x,__y,i)) {
            mark(__x,__y,i);
        }
    }
}
int main() {
    memset(valid,0,sizeof(valid));
    cin>>map_size;
    for(int i=0;i<map_size;i++) {
        for(int j=0;j<map_size;j++) {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<map_size;i++) {
        for(int j=0;j<map_size;j++) {
            if(map[i][j]=='y') _try(i,j);
        }
    }
    for(int i=0;i<map_size;i++) {
        for(int j=0;j<map_size;j++) {
            if(valid[i][j]) cout<<map[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}