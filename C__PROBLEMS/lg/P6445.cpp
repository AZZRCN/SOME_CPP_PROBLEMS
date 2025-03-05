#include <iostream>
#include <stack>
using namespace std;
int t;
stack<int> s;
void invoke(){
    int len = 0;
    int mul = 1;
    while(t>=mul){
        t-=mul;
        len++;
        mul*=2;
    }
    while(len-->0){
        s.push(t&1);
        t>>=1;
    }
    while(!s.empty()){
        if(s.top()){
            putchar('7');
        }
        else{
            putchar('4');
        }
        s.pop();
    }
}
int main(){
    cin >> t;
    invoke();
}