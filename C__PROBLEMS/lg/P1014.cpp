#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin >> n;
    for(i = 1; i < n; i++){
        n-=i;
    }
    if(i%2==0){
        printf("%d/%d",n,i+1-n);
    }
    else{
        printf("%d/%d",i+1-n,n);
    }
}