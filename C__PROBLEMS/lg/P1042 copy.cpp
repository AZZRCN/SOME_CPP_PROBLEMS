#include <bits/stdc++.h>
using namespace std;
#ifndef __forceinline
#define freopen
#endif
vector<pair<int,int>> v11;
vector<pair<int,int>> v21;
int main(){
    //W is 1
    //L is 0
    int a=0,b=0,c=0,d=0;
    freopen("..\\in","r",stdin);
    string t;
    bool end = false;
    while(!end){
        cin >> t;
        for(const char&ch:t){
            if(ch=='E'){
                end = true;
                break;
            }
            (ch=='W')?(a++,c++):(b++,d++);
            if(max(a,b)>=11&&abs(a-b)>=2){
                v11.push_back(make_pair(a,b));
                a=0;
                b=0;
            }
            if(max(c,d)>=21&&abs(c-d)>=2){
                v21.push_back(make_pair(c,d));
                c=0;
                d=0;
            }
        }
    }
        v11.push_back(make_pair(a,b));
        v21.push_back(make_pair(c,d));
    for(auto k:v11){
        printf("%d:%d\n",k.first,k.second);
    }
    printf("\n");
    for(auto k:v21){
        printf("%d:%d\n",k.first,k.second);
    }
}