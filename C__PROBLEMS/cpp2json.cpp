#include <bits/stdc++.h>
using namespace std;
#define p(x) putchar(x)
int main(){
    freopen("convert.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int c;
    bool ifc = true;//is first and space;
    p('\"');
    while(!feof(stdin)){
        switch (c = getchar())
        {
        case '\n':
            p('\"');
            p(',');
            p('\n');
            p('\"');
            ifc = true;
            break;
        case '\"':
            p('\\');
            p('\"');
            break;
        case ' ':
        case '\t':
            if(ifc){
                break;
            }
            p(c);
            break;
        default:
            p(c);
            ifc = false;
            break;
        }
    }
    p('\"');
}