#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
vector<string>b;
queue<string> c;
stack<string> d;
int main(){
    int n;
    cin >> n;
    string s,o;
    b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s >> o;
        if(o=="SAME"){
            b[i]=s;
        } else if(o == "UP"){
            d.push(s);//low
        } else {
            c.push(s);//high
        }
    }
    int cur = 0;
    while(!c.empty()){
        while(!b[cur].empty()){
            cur++;
        }
        b[cur]=c.front();
        cur++;
        c.pop();
    }
    cur = b.size()-1;
    while(!d.empty()){
        while(!b[cur].empty()){
            cur--;
        }
        b[cur]=d.top();
        cur--;
        d.pop();
    }
    for(string& str:b){
        cout << str << endl;
    }
}