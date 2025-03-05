#include <bits/stdc++.h>
using namespace std;
int main(){
    string str = "54321";
    for(int i = 1; i <= 120; i++){
        next_permutation(str.begin(),str.end());
        printf("%d|%s\n",i,str.c_str());
    }
}