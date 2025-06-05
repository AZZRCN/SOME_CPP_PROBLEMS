#include <bits/stdc++.h>
#ifndef __forceinline
#define freopen
#endif
#define release {\
printf("%d:%d\n",a,b);\
            a=0;\
            b=0;\
            cnt = 0;\
            outed = true;\
}
using namespace std;
vector<int> v;
void process(int x){
    int a=0,b=0,cnt = 0;
    bool outed = false;
    for(const int& i:v){
        (i)?(a++):(b++);
        if(max(a,b)>=x&&abs(a-b)>=2){
            release;
        }
    }
    release;
}
int main(){
    //W is 1
    //L is 0
    freopen("..\\in","r",stdin);
    bool end = false;
    while(!end){
        char c;
        cin >> c;
        if(c=='E'){
            end = true;
            break;
        }
        v.push_back(c=='W');
    }
    process(11);
    printf("\n");
    process(21);
}