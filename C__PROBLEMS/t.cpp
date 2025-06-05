#include <bits/stdc++.h>
using namespace std;
int abc = 1;
int& f(){
    return abc;
}
int main(){
    f()=2;
    cout << abc;
}